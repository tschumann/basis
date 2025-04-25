#!/bin/bash

set -eu

cd $(dirname "${BASH_SOURCE[0]}")

# initialise the repo by building all necessary projects etc

source ./settings.sh

# need to create these, otherwise the compile scripts don't copy correctly
mkdir -p $MODDIR/cl_dlls/
mkdir -p $MODDIR/dlls/
mkdir -p $MODDIR/maps/
mkdir -p $MODDIR/models/
mkdir -p $MODDIR/sprites/
