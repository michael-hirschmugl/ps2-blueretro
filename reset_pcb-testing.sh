#!/bin/bash

# Delete everything except the .git folder
find . -mindepth 1 -not -path "./.git*" -delete

# Check out the pcb-testing branch
git checkout pcb-testing --force

# Initialize and update submodules
git submodule update --init --recursive
