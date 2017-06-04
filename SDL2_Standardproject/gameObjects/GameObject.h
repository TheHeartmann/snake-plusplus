#pragma once

#include "board/grid/Point2D.h"
#include "SDL/SDLBmp.h"
#include <memory>
#include <SDL/SDLPng.h>

class GameObject {
public:
    GameObject(Point2D newPosition, std::shared_ptr<SDLPng> newImage, Direction rotation);

    Point2D getPosition();

    void setPosition(Point2D newPosition);

    SDLPng *getImage();

    void setImage(SDLPng *newImage);

    void rotate(Direction newDirection);

    Direction getDirection();

    Point2D getPreviousPosition();

    void setPreviousPosition(Point2D position);

    void follow(GameObject *bodyPart);

    float getTurnX();

    float getTurnY();

    void setTurnX(float newX);

    void setTurnY(float newY);

private:
    Point2D previousPosition;
    Point2D position;
    Direction direction;
    SDLPng *image;
    float turnX;
    float turnY;
};

