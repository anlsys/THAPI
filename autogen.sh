#!/bin/sh
# NOTE: this tree builds out-of-tree, the way the upstream README describes:
#
#     ./autogen.sh && mkdir build && cd build
#     ../configure --prefix=/lus/flare/projects/pe-summer-26/jshim/THAPI-INSTALL/ici
#     make -j install
#
# Source the build environment first (compilers, h2yaml, metababel, gems):
#
#     . /flare/pe-summer-26/jshim/thapi_build_shell.sh
#
# A leftover in-source configure (config.status/Makefile here, from an older
# `spack develop` build) makes autotools refuse the VPATH build with
# "source directory already configured". Clear it with `make distclean`.
#
# See /flare/pe-summer-26/jshim/BUILD_FROM_README.md.
if [ -f config.status ]; then
    echo "autogen.sh: WARNING: an in-source configure is present here." >&2
    echo "  An out-of-tree '../configure' from build/ WILL fail." >&2
    echo "  Run 'make distclean' first, then re-run ./autogen.sh." >&2
    echo "  NOTE: distclean also removes some tracked files; restore with" >&2
    echo "    git checkout -- \$(git diff --name-only --diff-filter=D)" >&2
    echo >&2
fi
set -x
autoreconf -vif -I m4
