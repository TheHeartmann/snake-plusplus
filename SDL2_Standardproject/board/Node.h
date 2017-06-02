//
// Created by clement on 01/06/17.
//

#ifndef SNAKE_PLUSPLUS_NODE_H
#define SNAKE_PLUSPLUS_NODE_H

#include "board/grid/Vector2D.h"

enum class NodeType { space, apple, snake };

class Node {

public:

    int grid_x;
    int grid_y;
    NodeType type;

    Node();

    Node(int _grid_x, int _grid_y, NodeType type = NodeType::space);

    Node(const Node &node);

    Node(Node &&node);

    Node &operator=(const Node &node);

    Node &operator=(Node &&node);

    bool is(const NodeType &type) const;

    bool hasSamePosition(const Node& rhs) const;

    //friend bool operator==(Node& rhs, Node& lhs);
    bool operator==(const Node& lhs) const;

    //friend bool operator!=(Node& rhs, Node& lhs);
    bool operator!=(const Node& lhs) const;

    Node operator+(Vector2D& rhs);

    ~Node();
};


#endif //SNAKE_PLUSPLUS_NODE_H
