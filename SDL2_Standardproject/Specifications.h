//
// Created by clement on 02/06/17.
//
#pragma once

#ifndef SNAKE_PLUSPLUS_SPECIFICATIONS_H
#define SNAKE_PLUSPLUS_SPECIFICATIONS_H

#define BOARD_COLS_MAC 30
#define BOARD_ROWS_MAC 20
#define NODE_DIAMETER_PIXELS 20

#include <gameObjects/GameObject.h>

static const struct Specs {
    Specs() {}


    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 400;

    const int BOARD_RENDER_WIDTH_PX = 600;
    const int BOARD_RENDER_HEIGHT_PX = 400;

    const int BOARD_COLUMNS = 30;
    const int BOARD_ROWS = 20;
    const int NODE_DIAMETER_PX = 20;
    const int NODE_RADIUS_PX = NODE_DIAMETER_PX / 2;

    const int SNAKE_INITIAL_LENGTH = 4;
    const double SNAKE_SPEED = 150.0;
    const int SNAKE_ACCELERATION = 10;
    const Direction SNAKE_HEAD_STARTDIR = Direction::RIGHT;
    double MINIMUM_SPAWN_RADIUS = 5.d;

} Specs;


#endif //SNAKE_PLUSPLUS_SPECIFICATIONS_H
