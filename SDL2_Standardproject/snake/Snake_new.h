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
    Snake_new();
    Snake_new(initializer_list<shared_ptr<Node>> _body);
    Snake_new(list<shared_ptr<Node>> _body);

    ~Snake_new();

	shared_ptr<const Node> getHead() const;

    const Node& getTail() const;

    inline unsigned long getLength() const { return body.size(); }

    void move(shared_ptr<Node> newHeadPosition);

    void grow(shared_ptr<Node> newHeadPosition);

private:
    list<shared_ptr<Node>> body{};
};

#endif //SNAKE_PLUSPLUS_SNAKE_NEW_H
