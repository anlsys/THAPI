#!/bin/sh
exec_prefix=/lus/flare/projects/pe-summer-26/jshim/THAPI-INSTALL/ici
libdir=${exec_prefix}/lib
pkglibdir=$libdir/thapi
prefix=/lus/flare/projects/pe-summer-26/jshim/THAPI-INSTALL/ici
datarootdir=${prefix}/share
datadir=${datarootdir}

display_help() {
  echo "Usage:"
  echo " $(basename $0) [options] [--] <application> <application-arguments>"
  echo "  --help                        Show this screen"
  echo "  --version                     Print the version string"
  exit 1
}

display_version() {
  cat $datadir/thapi_version
  exit 1
}

intel_extensions=true
while true; do
  case "$1" in
    --help)
      display_help
      exit
      ;;
    --version)
      display_version
      exit
      ;;
    --)
      shift
      break
      ;;
    *) break ;;
  esac
done

if [ "$#" -eq 0 ]; then
  display_help
fi

lttng-sessiond --daemonize --quiet
lttng create thapi-itt-session

lttng enable-channel --userspace --blocking-timeout=inf blocking-channel
lttng add-context --userspace --channel=blocking-channel -t vpid -t vtid
lttng enable-event --channel=blocking-channel --userspace lttng_ust_itt:*
lttng enable-event --channel=blocking-channel --userspace lttng_ust_itt_metadata:*

export INTEL_LIBITTNOTIFY64=$libdir/libittnotify.so
export LTTNG_UST_ALLOW_BLOCKING=1

lttng start

ctrl_c() {
  lttng stop
  lttng destroy
  exit
}

trap ctrl_c INT

"$@"
lttng stop
lttng destroy
