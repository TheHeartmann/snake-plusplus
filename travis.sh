#!/usr/bin/env bash

# create cmake-build-debug dir
sudo mkdir cmake-build-debug

# build to directory
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"

# build test project
cmake --build . --target runSnakePlusPlusTests

# build executable program
cmake --build . --target snake-plusplus_run

# run tests
SnakePlusPlusTests/basic_tests/runSnakePlusPlusTests --gtest_filter=* --gtest_color=no

# run program
# ./snake-plusplus_run