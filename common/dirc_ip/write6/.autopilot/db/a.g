#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/ylxiao/ws_183/F200703/dirc/write6/.autopilot/db/a.g.bc ${1+"$@"}
