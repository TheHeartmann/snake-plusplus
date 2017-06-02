//
// Created by clement on 02/06/17.
//

#ifndef SNAKE_PLUSPLUS_SNAKE_NEW_H
#define SNAKE_PLUSPLUS_SNAKE_NEW_H

#include <vector>
#include <memory>
#include "Node.h"
#include "Specifications.h"

using namespace std;
class Snake_new{
public:
    Snake_new(int length = Specs.SNAKE_INITIAL_LENGTH);
    Node getHead();
    Node getTail;


private:
    vector<unique_ptr<Node>> body;
};

#endif //SNAKE_PLUSPLUS_SNAKE_NEW_H
