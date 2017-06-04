#!/usr/bin/env bash

sudo apt-get install cmake libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev

#create the directory for
sudo mkdir cmake-build-debug

# build executable program
cmake --build cmake-build-debug --target snake-plusplus_run

#run game
sh ./play.sh