#include "GameObject.h"


GameObject::GameObject(Point2D newPosition, SDLBmp *newImage, Direction newRotation) {

    position = newPosition;
    image = newImage;
    direction = newRotation;
    turnX = position.getX();
    turnY = position.getY();
}

Point2D GameObject::getPosition() {
    return position;
}

void GameObject::setPosition(Point2D newPosition) {
    position = newPosition;
}

SDLBmp *GameObject::getImage() {
    image->x = this->getPosition().getX();
    image->y = this->getPosition().getY();
    return image;
}

void GameObject::setImage(SDLBmp *newImage) {
    image = newImage;
}

void GameObject::rotate(Direction newDirection) {
    direction = newDirection;
}

Direction GameObject::getDirection() {
    return direction;
}

Point2D GameObject::getPreviousPosition() {
    return previousPosition;
}

void GameObject::setPreviousPosition(Point2D oldPosition) {
    previousPosition = oldPosition;
}

void GameObject::follow(GameObject *bodyPart) {
    setPosition(bodyPart->getPreviousPosition());
}

float GameObject::getTurnX() {
    return turnX;
}

float GameObject::getTurnY() {
    return turnY;
}

void GameObject::setTurnX(float newX) {
    turnX = newX;
}

void GameObject::setTurnY(float newY) {
    turnY = newY;
}
