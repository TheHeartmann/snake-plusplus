//
// Created by clement on 01/06/17.
//

#ifndef SNAKE_PLUSPLUS_NODE_H
#define SNAKE_PLUSPLUS_NODE_H

#include "board/grid/Vector2D.h"
#include <memory>

using namespace std;

class Node {

public:

    int grid_x;
    int grid_y;

    Node();

    Node(int _grid_x, int _grid_y);

    Node(const Node &node);

    Node(Node &&node);

    Node &operator=(const Node &node);

    Node &operator=(Node &&node);


    bool hasSamePosition(const Node &rhs) const;

    bool operator==(const Node& lhs) const;

    bool operator!=(const Node& lhs) const;

    Node operator+(Vector2D& rhs) const;

    ~Node();
};


#endif //SNAKE_PLUSPLUS_NODE_H
