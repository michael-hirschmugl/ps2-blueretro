#!/bin/bash

# Delete everything except the .git folder
find . -mindepth 1 -not -path "./.git*" -delete

# Check out the main branch
git checkout main --force

# Initialize and update submodules
git submodule update --init --recursive
