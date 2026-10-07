#!/usr/bin/env python3
"""Synthesize CTF traces exercising the buffer-ownership (in-flight) checks.

Builds a trace where a rank stores into an MPI_Isend buffer before completing
the request (the violation), and one where the same store happens after
MPI_Wait (legal, must stay silent).

Mirrors the CTF conventions in make_trace.py: alignment in BITS, and one shared
clock uuid so traces can be muxed.

Usage: make_race_trace.py <dir> [race|clean] [hostname] [trace-uuid]
"""
import os
import struct
import sys

TRACE_DIR = sys.argv[1] if len(sys.argv) > 1 else "race_trace"
MODE = sys.argv[2] if len(sys.argv) > 2 else "race"
HOSTNAME = sys.argv[3] if len(sys.argv) > 3 else "racehost"
UUID_STR = sys.argv[4] if len(sys.argv) > 4 else "12121212-3434-5656-7878-909090909090"
CLOCK_UUID = "99999999-8888-7777-6666-555555555555"
MAGIC = 0xC1FC1FC1

BUF = 0x1FFEFE8F60          # same shape as a real tracegrind stack buffer
COUNT = 1000
MPI_INT = 0x4C000405        # predefined handle, element size 4 in byte 2
REQ = 0xAC000000
ELEM = 4

METADATA = """/* CTF 1.8 */
typealias integer { size = 8;  align = 8; signed = false; } := uint8_t;
typealias integer { size = 32; align = 8; signed = false; } := uint32_t;
typealias integer { size = 64; align = 8; signed = false; } := uint64_t;
typealias integer { size = 32; align = 8; signed = true;  } := int32_t;
typealias integer { size = 64; align = 8; signed = true;  } := int64_t;

trace {
	major = 1;
	minor = 8;
	uuid = "%s";
	byte_order = le;
	packet.header := struct {
		uint32_t magic;
		uint8_t  uuid[16];
		uint32_t stream_id;
	};
};

env {
	hostname = "%s";
	domain = "ust";
};

clock {
	name = "monotonic";
	uuid = "%s";
	freq = 1000000000;
	offset = 0;
};

typealias integer {
	size = 64; align = 8; signed = false;
	map = clock.monotonic.value;
} := uint64_clock_monotonic_t;

stream {
	id = 0;
	event.header := struct {
		uint32_t id;
		uint64_clock_monotonic_t timestamp;
	};
	packet.context := struct {
		uint64_clock_monotonic_t timestamp_begin;
		uint64_clock_monotonic_t timestamp_end;
		uint64_t packet_size;
		uint64_t content_size;
		uint32_t cpu_id;
	};
	event.context := struct {
		int64_t  vpid;
		uint64_t vtid;
	};
};

event { id = 0; name = "lttng_ust_mpi:MPI_Comm_size_entry"; stream_id = 0;
	fields := struct { uint64_t comm; uint64_t size; }; };
event { id = 1; name = "lttng_ust_mpi:MPI_Comm_size_exit"; stream_id = 0;
	fields := struct { int32_t mpiResult; int32_t size_val; }; };
event { id = 2; name = "lttng_ust_mpi:MPI_Comm_rank_entry"; stream_id = 0;
	fields := struct { uint64_t comm; uint64_t rank; }; };
event { id = 3; name = "lttng_ust_mpi:MPI_Comm_rank_exit"; stream_id = 0;
	fields := struct { int32_t mpiResult; int32_t rank_val; }; };
event { id = 4; name = "lttng_ust_mpi:MPI_Isend_entry"; stream_id = 0;
	fields := struct { uint64_t buf; int32_t count; uint64_t datatype; int32_t dest; int32_t tag; uint64_t comm; uint64_t request; }; };
event { id = 5; name = "lttng_ust_mpi:MPI_Isend_exit"; stream_id = 0;
	fields := struct { int32_t mpiResult; uint64_t request_val; }; };
event { id = 6; name = "lttng_ust_mpi:MPI_Wait_entry"; stream_id = 0;
	fields := struct { uint64_t request; uint64_t status; uint64_t request_val; }; };
event { id = 7; name = "lttng_ust_mpi:MPI_Wait_exit"; stream_id = 0;
	fields := struct { int32_t mpiResult; }; };
event { id = 8; name = "lttng_ust_tracegrind:mem_accesses"; stream_id = 0;
	fields := struct {
		uint64_t seq;
		uint64_t user_ctx;
		uint32_t chunk;
		uint32_t n_loads;
		uint32_t _loads_length;
		uint64_t loads[_loads_length];
		uint32_t n_stores;
		uint32_t _stores_length;
		uint64_t stores[_stores_length];
	}; };
""" % (UUID_STR, HOSTNAME, CLOCK_UUID)

CSIZE_E, CSIZE_X = 0, 1
CRANK_E, CRANK_X = 2, 3
ISEND_E, ISEND_X = 4, 5
WAIT_E, WAIT_X = 6, 7
MEM = 8


class Events:
    def __init__(self):
        self.buf = b""

    def add(self, eid, ts, vpid, vtid, payload=b""):
        self.buf += struct.pack("<IQqQ", eid, ts, vpid, vtid) + payload


def mem(loads, stores, seq, ctx=0x1FFEFE8E60, chunk=0):
    """A tracegrind mem_accesses payload; loads/stores are flat [start,end) pairs."""
    p = struct.pack("<QQI", seq, ctx, chunk)
    p += struct.pack("<II", len(loads) // 2, len(loads))
    p += b"".join(struct.pack("<Q", a) for a in loads)
    p += struct.pack("<II", len(stores) // 2, len(stores))
    p += b"".join(struct.pack("<Q", a) for a in stores)
    return p


e = Events()
VP = 200
d20 = BUF + 20 * ELEM
store_d20 = [d20, d20 + 4]

e.add(CRANK_E, 1000, VP, VP, struct.pack("<QQ", 0x44000000, BUF - 0x100))
e.add(CRANK_X, 1100, VP, VP, struct.pack("<ii", 0, 0))
e.add(CSIZE_E, 1200, VP, VP, struct.pack("<QQ", 0x44000000, BUF - 0x200))
e.add(CSIZE_X, 1300, VP, VP, struct.pack("<ii", 0, 2))

e.add(ISEND_E, 1400, VP, VP,
      struct.pack("<QiQiiQQ", BUF, COUNT, MPI_INT, 1, 1, 0x44000000, BUF - 8))
e.add(ISEND_X, 1500, VP, VP, struct.pack("<iQ", 0, REQ))

if MODE == "race":
    # Store into the buffer while the Isend is still outstanding: a violation.
    e.add(MEM, 1600, VP, VP, mem([], store_d20, 8))
    # Leave the request outstanding too, so the "never completed" check fires.
else:
    # Complete the request first, then store: legal, must stay silent.
    e.add(WAIT_E, 1600, VP, VP, struct.pack("<QQQ", BUF - 8, 0, REQ))
    e.add(WAIT_X, 1700, VP, VP, struct.pack("<i", 0))
    e.add(MEM, 1800, VP, VP, mem([], store_d20, 8))

content = e.buf
header = struct.pack("<I", MAGIC) + bytes.fromhex(UUID_STR.replace("-", "")) \
         + struct.pack("<I", 0)
ctx_size = 8 + 8 + 8 + 8 + 4
total_bits = (len(header) + ctx_size + len(content)) * 8
context = struct.pack("<QQQQI", 1000, 2000, total_bits, total_bits, 3)

os.makedirs(TRACE_DIR, exist_ok=True)
with open(os.path.join(TRACE_DIR, "metadata"), "w") as f:
    f.write(METADATA)
with open(os.path.join(TRACE_DIR, "channel0_0"), "wb") as f:
    f.write(header + context + content)
print("wrote", TRACE_DIR, "mode=" + MODE)
