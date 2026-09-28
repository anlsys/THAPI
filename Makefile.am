# Install the pkg-config file
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = thapi.pc

ACLOCAL_AMFLAGS = -I m4

# Only built when configured with --with-tracegrind: the hook needs the
# tracegrind fork's headers. Always distributed, hence DIST_SUBDIRS.
if TRACEGRIND
TRACEGRIND_SUBDIR = backends/tracegrind
endif

THAPI_SUBDIRS = utils xprof sampling backends/opencl backends/ze backends/cuda backends/omp backends/hip backends/mpi backends/cxi backends/itt backends/pytorch

SUBDIRS = $(THAPI_SUBDIRS) $(TRACEGRIND_SUBDIR)
DIST_SUBDIRS = $(THAPI_SUBDIRS) backends/tracegrind

EXTRA_DIST = autogen.sh README.md .valgrind/dlopen.supp thapi.pc.in

CLEANFILES = thapi.pc
