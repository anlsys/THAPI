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

echo "error handling"
out=$($VALIDATOR /nonexistent 2>&1); rc=$?
check "missing path reported" "mpi_validator:" "$out"
[[ $rc -eq 2 ]] && echo "  ok: exit code 2 on setup failure" \
	|| { echo "  FAIL: exit code $rc, want 2"; fail=1; }

echo
[[ $fail -eq 0 ]] && echo "all tests passed" || echo "FAILURES"
exit $fail
