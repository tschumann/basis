#!/bin/bash

set -eu

cd $(dirname "${BASH_SOURCE[0]}")

# initialise the repo by building all necessary projects etc

# install required dependencies
sudo apt-get install gcc-multilib g++-multilib mesa-common-dev libgl-dev

sh ./settings.sh

# need to create these, otherwise the compile scripts don't copy correctly
mkdir $MODDIR/cl_dlls/
mkdir $MODDIR/dlls/
mkdir $MODDIR/maps/
mkdir $MODDIR/models/
mkdir $MODDIR/sprites/
