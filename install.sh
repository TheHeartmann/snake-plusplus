#!/usr/bin/env bash

sudo mkdir cmake-build-debug

# build to directory
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"

# build executable program
cmake --build cmake-build-debug --target snake-plusplus_run

#run game
sh ./play.sh