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
    Snake_new(initializer_list<Node> _body);
    Snake_new(list<Node> _body);

    ~Snake_new();

	Node getHead() const;

	Node getTail() const;

	list<Node> getBody() const;

    inline unsigned long getLength() const { return body.size(); }

    void move(Node& newHeadPosition);

    void grow(Node& newHeadPosition);

//	bool operator==(const Snake_new& rhs) const;
//
//	bool operator!=(const Snake_new& rhs) const;

private:
    list<Node> body{};
};

#endif //SNAKE_PLUSPLUS_SNAKE_NEW_H
