//
// Created by clement on 02/06/17.
//

#ifndef SNAKE_PLUSPLUS_SNAKE_NEW_H
#define SNAKE_PLUSPLUS_SNAKE_NEW_H

#include <list>
#include <memory>
#include "board/Node.h"
#include "Specifications.h"

using namespace std;

class Snake_new {
public:
    Snake_new(initializer_list<Node> _body);

    ~Snake_new();

    Node getHead() const;

    Node getTail() const;

    inline ulong getLength() const { return body->size(); }

    void move(Node newHeadPosition);

    void grow(Node newHeadPosition);

private:
    list<Node> *body;
};

#endif //SNAKE_PLUSPLUS_SNAKE_NEW_H
