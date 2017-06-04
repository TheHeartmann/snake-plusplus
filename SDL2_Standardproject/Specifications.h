//
// Created by clement on 02/06/17.
//
#pragma once

#ifndef SNAKE_PLUSPLUS_SPECIFICATIONS_H
#define SNAKE_PLUSPLUS_SPECIFICATIONS_H

#include "Direction.h"

#define BOARD_COLS_MAC 30
#define BOARD_ROWS_MAC 20
#define NODE_DIAMETER_PIXELS 20


static const struct Specs {
    Specs() {}


    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 400;


    const int BOARD_COLUMNS = 30;
    const int BOARD_ROWS = 20;
    const int NODE_DIAMETER_PX = 20;
    const Direction SNAKE_HEAD_STARTDIR = Direction::RIGHT;
    double MINIMUM_SPAWN_RADIUS = 5.d;

    const int OBSTACLE_SPAWN_RATE = 10;

    // time range between in seconds
    const int MIN_APPLE_RESPAWN_TIME = 5;
    const int APPLESPAWN_TIME_DELTA = 3;
    const float MAX_MOVE_INTERVAL = 10.f/60.f;
    const float MIN_MOVE_INTERVAL = 3.f/60.f;
} Specs;


#endif //SNAKE_PLUSPLUS_SPECIFICATIONS_H
