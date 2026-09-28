if STRICT
  WERROR = -Werror
else
  WERROR =
endif

TRACEGRIND_STATIC_PROBES = tracegrind_tracepoints

TRACEGRIND_STATIC_PROBES_TP = $(TRACEGRIND_STATIC_PROBES:=.tp)

TRACEGRIND_STATIC_PROBES_INCL = $(TRACEGRIND_STATIC_PROBES:=.h)

TRACEGRIND_STATIC_PROBES_SRC = $(TRACEGRIND_STATIC_PROBES:=.c)

# The provider is named after the tool but the generated files are not: a
# `tracegrind.h` sitting in the build dir would shadow Valgrind's installed
# <valgrind/tracegrind.h>, which the hook includes. So the provider name is
# passed explicitly instead of being derived from the file stem.
$(TRACEGRIND_STATIC_PROBES_TP): %.tp: $(top_srcdir)/utils/gen_custom_probes.rb $(srcdir)/tracegrind_events.yaml $(top_srcdir)/utils/gen_probe_base.rb
	$(RUBY) $< $(srcdir)/tracegrind_events.yaml lttng_ust_tracegrind > $@

%.h %.c: %.tp
	$(LTTNG_GEN_TP) $< -o $*.c -o $*.h

noinst_LTLIBRARIES = libtracegrindtracepoints.la

nodist_libtracegrindtracepoints_la_SOURCES = \
	$(TRACEGRIND_STATIC_PROBES_INCL) \
	$(TRACEGRIND_STATIC_PROBES_SRC)

libtracegrindtracepoints_la_CPPFLAGS = -I$(top_srcdir)/utils -I$(top_srcdir)/utils/include -I./
libtracegrindtracepoints_la_CFLAGS = -fPIC -Wall -Wextra -Wno-unused-parameter $(WERROR) $(LTTNG_UST_CFLAGS)
libtracegrindtracepoints_la_LDFLAGS = $(LTTNG_UST_LIBS)

# LD_PRELOAD'd by `iprof --valgrind` so that Valgrind's redirection engine can
# see the _vgw... wrapper symbol and bind it onto liblttng-ust's internal
# lttng_event_reserve(). Nothing ever links against this object.
lib_LTLIBRARIES = libTracerTracegrind.la

# tracegrind_tracepoints.c is only built once, into libtracegrindtracepoints.la
# above; pull it in via LIBADD rather than compiling it again here (a second
# copy would clash with the first at link time: duplicate tracepoint symbols).
nodist_libTracerTracegrind_la_SOURCES = \
	$(TRACEGRIND_STATIC_PROBES_INCL)

libTracerTracegrind_la_SOURCES = \
	tracer_tracegrind.c

libTracerTracegrind_la_CPPFLAGS = -I$(top_srcdir)/utils -I$(top_srcdir)/utils/include -I./ $(TRACEGRIND_CPPFLAGS)
# -Wno-unused-but-set-variable: valgrind.h's client-request macros assign to a
#   result variable the statement forms never read.
libTracerTracegrind_la_CFLAGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-variable $(WERROR) $(LTTNG_UST_CFLAGS)
libTracerTracegrind_la_LDFLAGS = $(LTTNG_UST_LIBS) -avoid-version -module
libTracerTracegrind_la_LIBADD = libtracegrindtracepoints.la

EXTRA_DIST = \
	tracegrind_events.yaml \
	README.md \
	$(top_srcdir)/utils/gen_custom_probes.rb

CLEANFILES = \
	$(TRACEGRIND_STATIC_PROBES_TP) \
	$(TRACEGRIND_STATIC_PROBES_INCL) \
	$(TRACEGRIND_STATIC_PROBES_SRC)

BUILT_SOURCES = \
	$(TRACEGRIND_STATIC_PROBES_INCL)
