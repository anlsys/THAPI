#!/bin/bash
# Regenerates the synthetic CTF fixtures and checks mpi_validator's output.
set -u
cd "$(dirname "$0")"

# The environment (ruby, the babeltrace2 gem, GEM_PATH) now comes from
# setup_thapi_tracegrind_env.sh, not the old standalone setup_env.sh. Prefer an
# installed mpi_validator on PATH; fall back to the one built in this tree.
if command -v mpi_validator >/dev/null 2>&1; then
	VALIDATOR=$(command -v mpi_validator)
elif [[ -x ../mpi_validator ]]; then
	VALIDATOR=../mpi_validator
else
	echo "no mpi_validator found: source setup_thapi_tracegrind_env.sh, or build THAPI" >&2
	exit 2
fi
echo "using $VALIDATOR"
fail=0

check() { # check <label> <expected substring> <actual>
	if [[ "$3" == *"$2"* ]]; then
		echo "  ok: $1"
	else
		echo "  FAIL: $1 -- expected to find '$2'"
		fail=1
	fi
}

echo "regenerating fixtures"
python3 make_trace.py ctf_trace >/dev/null
rm -rf multi && mkdir -p multi
python3 make_trace.py multi/trace_a hostA \
	11111111-2222-3333-4444-555555555555 >/dev/null
python3 make_trace.py multi/trace_b hostB \
	aaaaaaaa-bbbb-cccc-dddd-eeeeeeeeeeee >/dev/null

echo "single trace"
out=$($VALIDATOR -v ctf_trace 2>&1); rc=$?
check "entry dispatch"           'MPI_Send entry: {"comm"=>32768, "dest"=>1'   "$out"
check "successful exit dispatch" 'MPI_Send exit: {"mpiResult"=>0} (200 ns)'    "$out"
check "erroneous exit dispatch"  'ERROR [testhost:101:101] MPI_Send returned 6' "$out"
check "entry args on error"      '"dest"=>99'                                  "$out"
check "non entry/exit event"     'lttng_ust_mpi_type:property'                 "$out"
check "dangling entry reported"  'MPI_Recv entered but never returned'         "$out"
check "call tally"               '4 MPI calls across 2 distinct APIs'          "$out"
[[ $rc -eq 1 ]] && echo "  ok: exit code 1 when issues found" \
	|| { echo "  FAIL: exit code $rc, want 1"; fail=1; }

echo "multiple traces muxed"
out=$($VALIDATOR multi 2>&1)
check "first host seen"  "hostA" "$out"
check "second host seen" "hostB" "$out"
check "combined tally"   "8 MPI calls across 2 distinct APIs" "$out"

echo "buffer ownership (nonblocking in-flight)"
rm -rf race_trace clean_trace
python3 make_race_trace.py race_trace race racehost \
	12121212-3434-5656-7878-909090909090 >/dev/null
python3 make_race_trace.py clean_trace clean cleanhost \
	21212121-4343-6565-8787-090909090909 >/dev/null

out=$($VALIDATOR race_trace 2>&1)
check "store into in-flight Isend buffer" \
	'BUFFER RACE' "$out"
check "violation names the element"       'element [20]'                "$out"
check "violation names the request"       'MPI_Isend request 0xac000000' "$out"
check "uncompleted request reported"      'was never completed'          "$out"

# The same store after MPI_Wait is legal: the check must not fire.
out=$($VALIDATOR clean_trace 2>&1); rc=$?
if [[ "$out" == *"BUFFER RACE"* ]]; then
	echo "  FAIL: false positive after MPI_Wait"
	fail=1
else
	echo "  ok: no false positive once the request is completed"
fi
[[ $rc -eq 0 ]] && echo "  ok: exit code 0 when clean" \
	|| { echo "  FAIL: exit code $rc, want 0"; fail=1; }

echo "nonblocking request lifecycle"
rm -rf nb_trace && mkdir -p nb_trace
for s in $(python3 make_nonblocking_trace.py --list); do
	python3 make_nonblocking_trace.py "nb_trace/$s" "$s"
done
nb() { $VALIDATOR "nb_trace/$1" 2>&1; }
silent() { # silent <scenario> <label>: no issues and exit code 0
	local o rc
	o=$(nb "$1"); rc=$?
	if [[ $rc -eq 0 && "$o" != *"USAGE ERROR"* && "$o" != *"BUFFER RACE"* ]]; then
		echo "  ok: $2"
	else
		echo "  FAIL: $2 -- rc=$rc"; echo "$o" | sed 's/^/      /'; fail=1
	fi
}
silent waitall_clean      "Waitall by request-array slot, legal send-buffer read and concurrent sends"
silent waitsome_noindices "Waitsome without traced indices resolves when every candidate finished"
check "leak reported at MPI_Finalize"  'was never completed: still active at MPI_Finalize' "$(nb leak_finalize)"
check "Irecv/Isend buffer overlap"     'overlaps 200 byte(s) of the recv buffer of in-flight MPI_Irecv' "$(nb overlap)"
check "blocking Recv into in-flight Isend buffer" \
	'MPI_Recv recv buffer [0x7f0000001028, 0x7f0000001050) overlaps 40 byte(s)' "$(nb blocking_overlap)"
out=$(nb recv_read_race)
check "read of in-flight recv buffer"  'application read 4 byte(s) at 0x7f0000001028 (element [5]' "$out"
check "repeated races suppressed"      '1 repeated buffer race' "$out"
check "double completion"              'MPI_Wait on request 0xac000001, which was already completed' "$(nb double_wait)"
out=$(nb persistent)
check "race only while persistent request active" 'element [1] of the 40-byte send buffer' "$out"
[[ "$out" == *"element [0] of the 40-byte"* ]] && { echo "  FAIL: store to inactive persistent buffer reported"; fail=1; }
check "MPI_Start on active request"    'which is already active' "$out"
check "persistent request never freed" 'request 0xac000002 (peer=1, tag=4, send buffer 0x7f0000002000 (40 bytes)) was never freed' "$out"
out=$(nb waitany)
check "Waitany completes only indx"    'element [3] of the 400-byte recv buffer' "$out"
[[ "$out" == *"0x7f0000002000) while"* ]] && { echo "  FAIL: completed Waitany request still in flight"; fail=1; }
out=$(nb test_flag)
check "negative Test/Testall keeps request in flight" 'element [0] of the 400-byte send buffer' "$out"
[[ "$out" == *"element [1]"* || "$out" == *"never completed"* ]] \
	&& { echo "  FAIL: positive MPI_Test did not complete the request"; fail=1; }
out=$(nb free_active); rc=$?
check "Request_free on active request warns" 'WARNING [nbhost:300:300] MPI_Request_free on active MPI_Isend' "$out"
[[ $rc -eq 0 ]] && echo "  ok: warnings alone keep exit code 0" || { echo "  FAIL: exit code $rc, want 0"; fail=1; }
check "overwritten request variable"   'its MPI_Request variable was overwritten by MPI_Isend' "$(nb overwrite)"
check "requests from other calls tracked" 'MPI_Ibarrier request 0xac000001 created at 1100 was never completed' "$(nb generic)"

out=$(nb igather_root)
check "Igather root recv buffer is recvcount * comm size" \
	'element [15] of the 80-byte recv buffer' "$out"
[[ "$out" == *"application read"* ]] && { echo "  FAIL: read of Igather send buffer reported"; fail=1; }
out=$(nb iscatter_nonroot)
check "Iscatter recv buffer in flight off the root" 'element [2] of the 40-byte recv buffer' "$out"
[[ "$out" == *"0x7f0000001000) while"* || "$out" == *"send buffer at"* ]] \
	&& { echo "  FAIL: Iscatter send buffer tracked off the root"; fail=1; }
out=$(nb igather_in_place)
check "Irecv overlapping an in-place Igather recv buffer" \
	'overlaps 16 byte(s) of the recv buffer of in-flight MPI_Igather' "$out"
[[ "$out" == *"0xffffffffffffffff"* ]] && { echo "  FAIL: MPI_IN_PLACE treated as a buffer"; fail=1; }

echo "error handling"
out=$($VALIDATOR /nonexistent 2>&1); rc=$?
check "missing path reported" "mpi_validator:" "$out"
[[ $rc -eq 2 ]] && echo "  ok: exit code 2 on setup failure" \
	|| { echo "  FAIL: exit code $rc, want 2"; fail=1; }

echo
[[ $fail -eq 0 ]] && echo "all tests passed" || echo "FAILURES"
exit $fail
