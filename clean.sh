#!/bin/bash

set -eu

cd $(dirname "${BASH_SOURCE[0]}")

# clean the project by deleting all generated files

# code-related stuff
rm -f dlls/hl_i386.so
rm -rf release

# TODO: get rid of the above?
cd linux
make clean
cd ..

# filesystem testing stuff
rm -rf mod/
