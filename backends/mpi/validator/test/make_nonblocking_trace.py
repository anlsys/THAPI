#!/usr/bin/env python3
"""Synthesize CTF traces exercising the nonblocking-request checks.

One trace per scenario; run_tests.sh checks the validator output for each.
Request handles use the classic-MPICH int encoding (0xac......), stored in
4-byte slots of a request array, exactly as an application built against
Aurora's MPICH lays them out. The 8-byte value the tracer records carries
garbage in its upper half (it reads a standard-ABI MPI_Request), which the
fixtures reproduce so that normalization is exercised too.

Usage: make_nonblocking_trace.py <dir> <scenario>
       make_nonblocking_trace.py --list
"""
import os
import struct
import sys
import zlib

CLOCK_UUID = "99999999-8888-7777-6666-555555555555"
MAGIC = 0xC1FC1FC1
MPI_INT = 0x4C000405     # predefined, 4 bytes
MPI_DOUBLE = 0x4C00080B  # predefined, 8 bytes
COMM = 0x44000000
REQ_NULL = 0x2C000000
UNDEF = -32766
VP = 300

BUF_A = 0x7F0000001000
BUF_B = 0x7F0000002000
REQS = 0x7FFF00000100    # MPI_Request reqs[4]: slots at +0, +4, +8, +12
GARBAGE = 0xDEAD0000_00000000  # what the 8-byte read picks up past the int

# name -> (entry fields, exit fields); field = (ctf type, name)
U64, I32 = "uint64_t", "int32_t"
P2P = [(U64, "buf"), (I32, "count"), (U64, "datatype"), (I32, "peer"),
       (I32, "tag"), (U64, "comm"), (U64, "request")]
REQ_OUT = [(I32, "mpiResult"), (U64, "request_val")]
RES = [(I32, "mpiResult")]
COLL = [(U64, "sendbuf"), (I32, "sendcount"), (U64, "sendtype"), (U64, "recvbuf"),
        (I32, "recvcount"), (U64, "recvtype"), (I32, "root"), (U64, "comm"), (U64, "request")]
IN_PLACE = 0xFFFFFFFFFFFFFFFF  # classic MPICH (void*)-1
EVENTS = {
    "MPI_Isend": ([f if f[1] != "peer" else (I32, "dest") for f in P2P], REQ_OUT),
    "MPI_Irecv": ([f if f[1] != "peer" else (I32, "source") for f in P2P], REQ_OUT),
    "MPI_Send_init": ([f if f[1] != "peer" else (I32, "dest") for f in P2P], REQ_OUT),
    "MPI_Recv": ([(U64, "buf"), (I32, "count"), (U64, "datatype"), (I32, "source"),
                  (I32, "tag"), (U64, "comm"), (U64, "status")], RES),
    "MPI_Ibarrier": ([(U64, "comm"), (U64, "request")], REQ_OUT),
    "MPI_Wait": ([(U64, "request"), (U64, "status"), (U64, "request_val")], RES),
    "MPI_Test": ([(U64, "request"), (U64, "flag"), (U64, "status"), (U64, "request_val")],
                 [(I32, "mpiResult"), (I32, "flag_val")]),
    "MPI_Waitall": ([(I32, "count"), (U64, "array_of_requests"), (U64, "array_of_statuses")], RES),
    "MPI_Testall": ([(I32, "count"), (U64, "array_of_requests"), (U64, "flag"),
                     (U64, "array_of_statuses")], [(I32, "mpiResult"), (I32, "flag_val")]),
    "MPI_Waitany": ([(I32, "count"), (U64, "array_of_requests"), (U64, "indx"), (U64, "status")],
                    [(I32, "mpiResult"), (I32, "indx_val")]),
    "MPI_Waitsome": ([(I32, "incount"), (U64, "array_of_requests"), (U64, "outcount"),
                      (U64, "array_of_indices"), (U64, "array_of_statuses")],
                     [(I32, "mpiResult"), (I32, "outcount_val")]),
    "MPI_Start": ([(U64, "request"), (U64, "request_val")], RES),
    "MPI_Request_free": ([(U64, "request"), (U64, "request_val")], RES),
    "MPI_Finalize": ([], RES),
    "MPI_Comm_rank": ([(U64, "comm"), (U64, "rank")], [(I32, "mpiResult"), (I32, "rank_val")]),
    "MPI_Comm_size": ([(U64, "comm"), (U64, "size")], [(I32, "mpiResult"), (I32, "size_val")]),
    "MPI_Igather": (COLL, REQ_OUT),
    "MPI_Iscatter": (COLL, REQ_OUT),
}

NAMES = list(EVENTS)
MEM_ID = 2 * len(NAMES)


def metadata(uuid, host):
    out = ["""/* CTF 1.8 */
typealias integer { size = 8;  align = 8; signed = false; } := uint8_t;
typealias integer { size = 32; align = 8; signed = false; } := uint32_t;
typealias integer { size = 64; align = 8; signed = false; } := uint64_t;
typealias integer { size = 32; align = 8; signed = true;  } := int32_t;
typealias integer { size = 64; align = 8; signed = true;  } := int64_t;
trace { major = 1; minor = 8; uuid = "%s"; byte_order = le;
	packet.header := struct { uint32_t magic; uint8_t uuid[16]; uint32_t stream_id; }; };
env { hostname = "%s"; domain = "ust"; };
clock { name = "monotonic"; uuid = "%s"; freq = 1000000000; offset = 0; };
typealias integer { size = 64; align = 8; signed = false; map = clock.monotonic.value; }
	:= uint64_clock_monotonic_t;
stream { id = 0;
	event.header := struct { uint32_t id; uint64_clock_monotonic_t timestamp; };
	packet.context := struct { uint64_clock_monotonic_t timestamp_begin;
		uint64_clock_monotonic_t timestamp_end; uint64_t packet_size;
		uint64_t content_size; uint32_t cpu_id; };
	event.context := struct { int64_t vpid; uint64_t vtid; };
};
""" % (uuid, host, CLOCK_UUID)]
    for i, name in enumerate(NAMES):
        for j, (suffix, fields) in enumerate(zip(("entry", "exit"), EVENTS[name])):
            body = " ".join(f"{t} {n};" for t, n in fields) or "uint8_t _unused;"
            out.append(f'event {{ id = {2 * i + j}; name = "lttng_ust_mpi:{name}_{suffix}"; '
                       f"stream_id = 0; fields := struct {{ {body} }}; }};")
    out.append(f"""event {{ id = {MEM_ID}; name = "lttng_ust_tracegrind:mem_accesses"; stream_id = 0;
	fields := struct {{ uint64_t seq; uint64_t user_ctx; uint32_t chunk;
		uint32_t n_loads; uint32_t _loads_length; uint64_t loads[_loads_length];
		uint32_t n_stores; uint32_t _stores_length; uint64_t stores[_stores_length]; }}; }};""")
    return "\n".join(out) + "\n"


class Trace:
    def __init__(self):
        self.buf = b""
        self.ts = 1000

    def _ev(self, eid, payload):
        self.buf += struct.pack("<IQqQ", eid, self.ts, VP, VP) + payload
        self.ts += 100

    @staticmethod
    def _pack(fields, values):
        if not fields:
            return struct.pack("<B", 0)
        fmt = "<" + "".join("Q" if t == U64 else "i" for t, _ in fields)
        return struct.pack(fmt, *[values.get(n, 0) for _, n in fields])

    def call(self, name, entry=None, exit=None):
        i = NAMES.index(name)
        ent, ext = EVENTS[name]
        self._ev(2 * i, self._pack(ent, entry or {}))
        ex = {"mpiResult": 0, **(exit or {})}
        if "request_val" in ex:
            ex["request_val"] |= GARBAGE
        self._ev(2 * i + 1, self._pack(ext, ex))

    def mem(self, loads=(), stores=()):
        p = struct.pack("<QQI", 1, 0, 0)
        p += struct.pack("<II", len(loads) // 2, len(loads))
        p += b"".join(struct.pack("<Q", a) for a in loads)
        p += struct.pack("<II", len(stores) // 2, len(stores))
        p += b"".join(struct.pack("<Q", a) for a in stores)
        self._ev(MEM_ID, p)


def slot(i):
    return REQS + 4 * i


def isend(t, i, handle, buf=BUF_A, count=100, dtype=MPI_INT):
    t.call("MPI_Isend", dict(buf=buf, count=count, datatype=dtype, dest=1, tag=7,
                             comm=COMM, request=slot(i)), dict(request_val=handle))


def irecv(t, i, handle, buf=BUF_A, count=100, dtype=MPI_INT):
    t.call("MPI_Irecv", dict(buf=buf, count=count, datatype=dtype, source=1, tag=7,
                             comm=COMM, request=slot(i)), dict(request_val=handle))


def wait(t, i, handle):
    t.call("MPI_Wait", dict(request=slot(i), request_val=handle | GARBAGE))


def store(t, addr, n=4):
    t.mem(stores=[addr, addr + n])


def load(t, addr, n=4):
    t.mem(loads=[addr, addr + n])


H0, H1, H2 = 0xAC000001, 0xAC000002, 0xAC000003


def sc_waitall_clean(t):
    isend(t, 0, H0, BUF_A)
    irecv(t, 1, H1, BUF_B)
    load(t, BUF_A + 8)            # reading an in-flight send buffer is legal
    t.call("MPI_Waitall", dict(count=2, array_of_requests=REQS))
    store(t, BUF_A + 8)
    store(t, BUF_B + 8)
    isend(t, 2, H2, BUF_A)        # two concurrent sends from one buffer: legal
    isend(t, 3, H0, BUF_A)
    t.call("MPI_Waitall", dict(count=2, array_of_requests=slot(2)))
    t.call("MPI_Finalize")


def sc_leak_finalize(t):
    irecv(t, 0, H0)
    t.call("MPI_Finalize")


def sc_overlap(t):
    irecv(t, 0, H0, BUF_A, 100)
    isend(t, 1, H1, BUF_A + 200, 100)   # overlaps the receive buffer
    t.call("MPI_Waitall", dict(count=2, array_of_requests=REQS))


def sc_blocking_overlap(t):
    isend(t, 0, H0, BUF_A, 100)
    t.call("MPI_Recv", dict(buf=BUF_A + 40, count=10, datatype=MPI_INT, source=1,
                            tag=7, comm=COMM))
    wait(t, 0, H0)


def sc_recv_read_race(t):
    irecv(t, 0, H0, BUF_A, 100, MPI_DOUBLE)
    load(t, BUF_A + 8 * 5)
    load(t, BUF_A + 8 * 6)      # same request again: suppressed
    wait(t, 0, H0)


def sc_double_wait(t):
    isend(t, 0, H0)
    wait(t, 0, H0)
    wait(t, 1, H0)              # through a copy of the handle


def sc_persistent(t):
    t.call("MPI_Send_init", dict(buf=BUF_A, count=10, datatype=MPI_INT, dest=1, tag=3,
                                 comm=COMM, request=slot(0)), dict(request_val=H0))
    store(t, BUF_A)             # inactive: legal
    t.call("MPI_Start", dict(request=slot(0), request_val=H0 | GARBAGE))
    store(t, BUF_A + 4)         # active: race
    t.call("MPI_Start", dict(request=slot(0), request_val=H0 | GARBAGE))  # already active
    wait(t, 0, H0)
    t.call("MPI_Send_init", dict(buf=BUF_B, count=10, datatype=MPI_INT, dest=1, tag=4,
                                 comm=COMM, request=slot(1)), dict(request_val=H1))
    t.call("MPI_Request_free", dict(request=slot(0), request_val=H0 | GARBAGE))
    # H1 is never freed: warning only


def sc_waitany(t):
    irecv(t, 0, H0, BUF_A)
    irecv(t, 1, H1, BUF_B)
    t.call("MPI_Waitany", dict(count=2, array_of_requests=REQS), dict(indx_val=1))
    store(t, BUF_B)             # completed: legal
    store(t, BUF_A + 12)        # still in flight: race
    wait(t, 0, H0)


def sc_waitsome_noindices(t):
    # Old-style trace: no array_of_indices_vals. outcount == number of active
    # candidates, so all of them must have completed.
    isend(t, 0, H0, BUF_A)
    isend(t, 1, H1, BUF_B)
    t.call("MPI_Waitsome", dict(incount=2, array_of_requests=REQS), dict(outcount_val=2))
    store(t, BUF_A)
    store(t, BUF_B)
    t.call("MPI_Finalize")


def sc_test_flag(t):
    isend(t, 0, H0)
    t.call("MPI_Test", dict(request=slot(0), request_val=H0 | GARBAGE), dict(flag_val=0))
    t.call("MPI_Testall", dict(count=1, array_of_requests=REQS), dict(flag_val=0))
    store(t, BUF_A)             # still in flight after a negative test: race
    t.call("MPI_Test", dict(request=slot(0), request_val=H0 | GARBAGE), dict(flag_val=1))
    store(t, BUF_A + 4)         # completed now: legal
    t.call("MPI_Finalize")


def sc_free_active(t):
    isend(t, 0, H0)
    t.call("MPI_Request_free", dict(request=slot(0), request_val=H0 | GARBAGE))
    t.call("MPI_Finalize")


def sc_overwrite(t):
    isend(t, 0, H0, BUF_A)
    isend(t, 0, H1, BUF_B)      # same MPI_Request variable, H0 still active
    wait(t, 0, H1)
    t.call("MPI_Finalize")


def sc_generic(t):
    t.call("MPI_Ibarrier", dict(comm=COMM, request=slot(0)), dict(request_val=H0))
    t.call("MPI_Finalize")


def comm_setup(t, rank, size=2):
    t.call("MPI_Comm_rank", dict(comm=COMM), dict(rank_val=rank))
    t.call("MPI_Comm_size", dict(comm=COMM), dict(size_val=size))


def coll(t, name, i, handle, sendbuf, recvbuf, root=0, count=10):
    t.call(name, dict(sendbuf=sendbuf, sendcount=count, sendtype=MPI_INT, recvbuf=recvbuf,
                      recvcount=count, recvtype=MPI_INT, root=root, comm=COMM,
                      request=slot(i)), dict(request_val=handle))


def sc_igather_root(t):
    # Root of a 2-rank Igather: the receive buffer holds 10 ints from *each*
    # rank (80 bytes), so element [15] belongs to it.
    comm_setup(t, rank=0)
    coll(t, "MPI_Igather", 0, H0, BUF_A, BUF_B)
    store(t, BUF_B + 15 * 4)    # recv buffer, second rank's segment: race
    load(t, BUF_A + 4)          # reading the send buffer: legal
    wait(t, 0, H0)
    t.call("MPI_Finalize")


def sc_iscatter_nonroot(t):
    # Off the root, Iscatter's send buffer is not significant: only the
    # receive buffer is in flight.
    comm_setup(t, rank=1)
    coll(t, "MPI_Iscatter", 0, H0, BUF_A, BUF_B)
    store(t, BUF_A)             # sendbuf ignored off the root: legal
    store(t, BUF_B + 8)         # recv buffer: race
    wait(t, 0, H0)
    t.call("MPI_Finalize")


def sc_igather_in_place(t):
    # Root passes MPI_IN_PLACE as sendbuf: no send buffer; an Irecv into the
    # gather's receive buffer overlaps it.
    comm_setup(t, rank=0)
    coll(t, "MPI_Igather", 0, H0, IN_PLACE, BUF_B)
    irecv(t, 1, H1, BUF_B + 40, 4)
    t.call("MPI_Waitall", dict(count=2, array_of_requests=REQS))
    t.call("MPI_Finalize")


SCENARIOS = {k[3:]: v for k, v in globals().items() if k.startswith("sc_")}


def main():
    if sys.argv[1:] == ["--list"]:
        print("\n".join(SCENARIOS))
        return
    out, name = sys.argv[1], sys.argv[2]
    uuid = "%08x-0000-4000-8000-%012x" % (zlib.crc32(name.encode()), len(name))
    t = Trace()
    SCENARIOS[name](t)
    header = struct.pack("<I", MAGIC) + bytes.fromhex(uuid.replace("-", "")) + struct.pack("<I", 0)
    total_bits = (len(header) + 36 + len(t.buf)) * 8
    ctx = struct.pack("<QQQQI", 1000, t.ts, total_bits, total_bits, 0)
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, "metadata"), "w") as f:
        f.write(metadata(uuid, "nbhost"))
    with open(os.path.join(out, "channel0_0"), "wb") as f:
        f.write(header + ctx + t.buf)


main()
