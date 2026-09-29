#!/usr/bin/env python3
"""Synthesize a CTF 1.8 trace of THAPI-style MPI events.

The real THAPI traces reachable from this UAN only contain MPI_Init_entry (the
ranks abort before returning), so this builds a trace that exercises the paths
those cannot: successful exits, an erroneous exit, a non-entry/exit event, and
an entry left dangling with no matching exit.

Two CTF details worth knowing: alignment is specified in BITS (`align = 8` is
byte alignment, so the stream is simply byte-packed), and every trace to be
muxed together must share one clock uuid or utils.muxer refuses to correlate
them.

Usage: make_trace.py <dir> [hostname] [trace-uuid]
"""
import os
import struct
import sys

TRACE_DIR = sys.argv[1] if len(sys.argv) > 1 else "test/ctf_trace"
HOSTNAME = sys.argv[2] if len(sys.argv) > 2 else "testhost"
UUID_STR = sys.argv[3] if len(sys.argv) > 3 else "11111111-2222-3333-4444-555555555555"
# Must MATCH across traces, or the muxer reports "Unexpected clock class".
CLOCK_UUID = "99999999-8888-7777-6666-555555555555"
MAGIC = 0xC1FC1FC1

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

event { id = 0; name = "lttng_ust_mpi:MPI_Send_entry"; stream_id = 0;
	fields := struct { uint64_t comm; int32_t dest; int32_t tag; int32_t count; }; };
event { id = 1; name = "lttng_ust_mpi:MPI_Send_exit"; stream_id = 0;
	fields := struct { int32_t mpiResult; }; };
event { id = 2; name = "lttng_ust_mpi:MPI_Recv_entry"; stream_id = 0;
	fields := struct { uint64_t comm; int32_t source; int32_t tag; int32_t count; }; };
event { id = 3; name = "lttng_ust_mpi:MPI_Recv_exit"; stream_id = 0;
	fields := struct { int32_t mpiResult; }; };
event { id = 4; name = "lttng_ust_mpi_type:property"; stream_id = 0;
	fields := struct { uint64_t datatype; int32_t size; }; };
""" % (UUID_STR, HOSTNAME, CLOCK_UUID)


class Events:
    def __init__(self):
        self.buf = b""

    def add(self, eid, ts, vpid, vtid, payload=b""):
        # event header (id, timestamp) + event context (vpid, vtid) + payload
        self.buf += struct.pack("<IQqQ", eid, ts, vpid, vtid) + payload


SEND_ENTRY, SEND_EXIT, RECV_ENTRY, RECV_EXIT, PROPERTY = 0, 1, 2, 3, 4

e = Events()
# rank 0 (vpid 100): a clean Send then Recv, both MPI_SUCCESS
e.add(SEND_ENTRY, 1000, 100, 100, struct.pack("<Qiii", 0x8000, 1, 7, 4))
e.add(SEND_EXIT,  1200, 100, 100, struct.pack("<i", 0))
e.add(RECV_ENTRY, 1300, 100, 100, struct.pack("<Qiii", 0x8000, 1, 7, 4))
e.add(RECV_EXIT,  1500, 100, 100, struct.pack("<i", 0))
# rank 1 (vpid 101): a Send to an out-of-range rank -> MPI_ERR_RANK (6)
e.add(SEND_ENTRY, 1600, 101, 101, struct.pack("<Qiii", 0x8000, 99, 7, 4))
e.add(SEND_EXIT,  1700, 101, 101, struct.pack("<i", 6))
# a non entry/exit event -> on_other_event
e.add(PROPERTY,   1800, 101, 101, struct.pack("<Qi", 0xDEADBEEF, 8))
# a dangling entry: no matching exit, still on the call stack at end of trace
e.add(RECV_ENTRY, 1900, 101, 101, struct.pack("<Qiii", 0x8000, 0, 1, 16))

content = e.buf
header = struct.pack("<I", MAGIC) + bytes.fromhex(UUID_STR.replace("-", "")) \
         + struct.pack("<I", 0)
ctx_size = 8 + 8 + 8 + 8 + 4
total_bits = (len(header) + ctx_size + len(content)) * 8
context = struct.pack("<QQQQI", 1000, 1900, total_bits, total_bits, 3)

os.makedirs(TRACE_DIR, exist_ok=True)
with open(os.path.join(TRACE_DIR, "metadata"), "w") as f:
    f.write(METADATA)
with open(os.path.join(TRACE_DIR, "channel0_0"), "wb") as f:
    f.write(header + context + content)
print("wrote", TRACE_DIR)
