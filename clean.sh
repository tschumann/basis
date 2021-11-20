#!/bin/bash

set -e

cd $(dirname "${BASH_SOURCE[0]}")

# code-related stuff
rm -f dlls/hl_i386.so
rm -rf release

# filesystem testing stuff
rm -rf mod/
