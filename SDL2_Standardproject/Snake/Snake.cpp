#include "Snake.h"
#include <iostream>


Snake::Snake(GameObject *headPart, GameObject *bodyPart, int startingLength) {
    length = 3;
    headObject = headPart;
    bodyObject = bodyPart;

    this->push_front(GameObject(*headObject));
    this->push_back(GameObject(*bodyObject));
    this->push_back(GameObject(*bodyObject));
    this->push_back(GameObject(*bodyObject));

    getBodyPartAt(0)->setPosition(Point2D(getHead()->getPosition().getX() - bodyPart->getImage()->getWidth(),
                                          getHead()->getPosition().getY()));
    getBodyPartAt(1)->setPosition(Point2D(getBodyPartAt(0)->getPosition().getX() - bodyPart->getImage()->getWidth(),
                                          getHead()->getPosition().getY()));
    getBodyPartAt(2)->setPosition(Point2D(getBodyPartAt(1)->getPosition().getX() - bodyPart->getImage()->getWidth(),
                                          getHead()->getPosition().getY()));

    getBodyPartAt(0)->rotate(getHead()->getDirection());
    getBodyPartAt(1)->rotate(getHead()->getDirection());
    getBodyPartAt(2)->rotate(getHead()->getDirection());

    earlierTurns.push(Point2D(getBodyPartAt(0)->getPosition().getX() - bodyPart->getImage()->getWidth(),
                              getBodyPartAt(0)->getPosition().getY()));
    earlierTurns.push(Point2D(getBodyPartAt(1)->getPosition()));
    earlierTurns.push(Point2D(getBodyPartAt(2)->getPosition()));

}

void Snake::increaseLength() {
    length++;
    this->push_back(GameObject(*bodyObject));
}

int Snake::getLength() {
    return length;
}

GameObject *Snake::getHead() {
    return &this->front();
}

//pos -1 returns the head object.  
GameObject *Snake::getBodyPartAt(int pos) {
    auto snake_part = this->begin();
    std::advance(snake_part, pos + 1); //+1 to skip head
    return &*snake_part;
}


void Snake::updatePosition(Direction direction, float displacement) {
    //	auto newHead = *getHead ();
    //
    //	auto lastMove = newHead.getPosition ();


    // sets new position and direction for head based on direction
    auto head = getHead();

    switch (direction) {
        case Direction::LEFT:
            applyVelocity(head, -displacement, 0, Direction::LEFT);
            break;
        case Direction::RIGHT:
            applyVelocity(head, displacement, 0, Direction::RIGHT);
            break;
        case Direction::UP:
            applyVelocity(head, 0, -displacement, Direction::UP);
            break;
        case Direction::DOWN:
            applyVelocity(head, 0, displacement, Direction::DOWN);
     break;
    }

    //Sets new position and direction for rest of body
    for (auto i = 0; i <= length - 1; i++) {
        switch (getBodyPartAt(i)->getDirection()) {
            case Direction::LEFT:
                //left
                getBodyPartAt(i)->setPosition(Point2D(getBodyPartAt(i)->getPosition().getX() - displacement,
                                                      getBodyPartAt(i)->getPosition().getY()));

                if (getBodyPartAt(i)->getPosition().getX() < getBodyPartAt(i - 1)->getTurnX()) {
                    getBodyPartAt(i)->rotate(getBodyPartAt(i - 1)->getDirection());
                    getBodyPartAt(i)->setTurnX(getBodyPartAt(i - 1)->getPosition().getX());
                    getBodyPartAt(i)->getPosition().setX(getBodyPartAt(i - 1)->getPosition().getX());
                }
                break;
            case Direction::RIGHT:
                //right
                getBodyPartAt(i)->setPosition(Point2D(getBodyPartAt(i)->getPosition().getX() + displacement,
                                                      getBodyPartAt(i)->getPosition().getY()));

                if (getBodyPartAt(i)->getPosition().getX() > getBodyPartAt(i - 1)->getTurnX()) {
                    getBodyPartAt(i)->rotate(getBodyPartAt(i - 1)->getDirection());
                    getBodyPartAt(i)->setTurnX(getBodyPartAt(i - 1)->getPosition().getX());
                    getBodyPartAt(i)->getPosition().setX(getBodyPartAt(i - 1)->getPosition().getX());
                }
                break;
            case Direction::UP:
                //up
                getBodyPartAt(i)->setPosition(Point2D(getBodyPartAt(i)->getPosition().getX(),
                                                      getBodyPartAt(i)->getPosition().getY() - displacement));

                if (getBodyPartAt(i)->getPosition().getY() < getBodyPartAt(i - 1)->getTurnY()) {
                    getBodyPartAt(i)->rotate(getBodyPartAt(i - 1)->getDirection());
                    getBodyPartAt(i)->setTurnY(getBodyPartAt(i - 1)->getPosition().getY());
                    getBodyPartAt(i)->getPosition().setY(getBodyPartAt(i - 1)->getPosition().getY());
                }
                break;
            case Direction::DOWN:
                //down
                getBodyPartAt(i)->setPosition(Point2D(getBodyPartAt(i)->getPosition().getX(),
                                                      getBodyPartAt(i)->getPosition().getY() + displacement));

                if (getBodyPartAt(i)->getPosition().getY() > getBodyPartAt(i - 1)->getTurnY()) {
                    getBodyPartAt(i)->rotate(getBodyPartAt(i - 1)->getDirection());
                    getBodyPartAt(i)->setTurnY(getBodyPartAt(i - 1)->getPosition().getY());
                    getBodyPartAt(i)->getPosition().setY(getBodyPartAt(i - 1)->getPosition().getY());
                }
                break;
        }
    }

}

void Snake::applyVelocity(GameObject *obj, float vel_x, float vel_y, Direction dir) {
    auto oldPos = obj->getPosition();
    auto newX = oldPos.getX() + vel_x;
    auto newY = oldPos.getY() + vel_y;
    auto newPos = Point2D(newX, newY);
    obj->setPosition(newPos);
    obj->rotate(dir);

    if (vel_x != 0) obj->setTurnX(newX);
    else obj->setTurnY(newY);
}

void Snake::pushPreviousTurnPosition(Point2D lastPosition) {
    earlierTurns.push(lastPosition);
}

Point2D Snake::popPreviousTurnPosition() {
    auto popped = earlierTurns.back();
    earlierTurns.pop();
    return popped;
}

void Snake::drawSnake() {

    //	getBodyPartAt(0)->getImage ()->draw (getBodyPartAt(0)->getDirection ());


    for (auto i = 0; i <= length - 1; i++) {
        auto bodyPart = getBodyPartAt(0);
        int direction = static_cast<int>(bodyPart->getDirection());
        getBodyPartAt(i)->getImage()->draw(direction);
    }
    int headDirection = static_cast<int>(getHead()->getDirection());
    getHead()->getImage()->draw(headDirection);

}

Snake::Snake(int snakeLength) {
    length = snakeLength;
}
