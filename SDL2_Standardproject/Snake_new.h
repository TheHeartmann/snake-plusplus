//
// Created by clement on 02/06/17.
//

#ifndef SNAKE_PLUSPLUS_SNAKE_NEW_H
#define SNAKE_PLUSPLUS_SNAKE_NEW_H

#include <list>
#include <memory>
#include "Node.h"
#include "Specifications.h"

using namespace std;

class Snake_new{
public:
    Snake_new(const list<unique_ptr<Node>> _body): body{_body}{}

    unique_ptr<Node> getHead() const;
    unique_ptr<Node> getTail() const;
    inline ulong getLength() const { return body.size();}

    void move(const unique_ptr<Node> newHeadPosition);
    void grow(const unique_ptr<Node> newHeadPosition);

private:
    list<unique_ptr<Node>> body;
};

#endif //SNAKE_PLUSPLUS_SNAKE_NEW_H
