//
// Created by clement on 02/06/17.
//
#pragma once

#ifndef SNAKE_PLUSPLUS_SPECIFICATIONS_H
#define SNAKE_PLUSPLUS_SPECIFICATIONS_H

#include <gameObjects/GameObject.h>

static struct Specs {

    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 400;

    const int BOARD_WIDTH = 600;
    const int BOARD_HEIGHT = 400;
    const int NODE_DIAMETER = 20;
    const int NODE_RADIUS = NODE_DIAMETER/2;

    const int SNAKE_INITIAL_LENGTH = 4;
    const float SNAKE_SPEED = 150.0f;
    const int SNAKE_ACCELERATION = 10;
    const Direction SNAKE_HEAD_STARTDIR= Direction::RIGHT;
} Specs;


#endif //SNAKE_PLUSPLUS_SPECIFICATIONS_H
