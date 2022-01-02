#!/bin/bash

set -eu

cd $(dirname "${BASH_SOURCE[0]}")

# code-related stuff
rm -f dlls/hl_i386.so
rm -rf release

# TODO: get rid of the above?
cd linux
make clean
cd ..

# filesystem testing stuff
rm -rf mod/
