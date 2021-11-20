#!/bin/bash

set -e

cd $(dirname "${BASH_SOURCE[0]}")

sudo apt-get install libgl-dev

sh ./settings.sh

mkdir $MODDIR/cl_dlls/
mkdir $MODDIR/dlls/
# need to create these, otherwise the compile scripts don't copy correctly
mkdir $MODDIR/maps/
mkdir $MODDIR/models/
mkdir $MODDIR/sprites/

# TODO: check that files with the same names as the filesystem testing assets don't exist in $MODDIR
