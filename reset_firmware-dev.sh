#!/bin/bash

# Delete everything except the .git folder
find . -mindepth 1 -not -path "./.git*" -delete

# Check out the firmware-dev branch
git checkout firmware-dev --force

# Initialize and update submodules
git submodule init
git submodule update # --init --recursive
