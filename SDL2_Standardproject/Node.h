//
// Created by clement on 01/06/17.
//

#ifndef SNAKE_PLUSPLUS_NODE_H
#define SNAKE_PLUSPLUS_NODE_H

enum class NodeType{ space, apple, snake };

class Node {

public:
    int grid_x;
    int grid_y;
    NodeType type;

    Node(int _grid_x, int _grid_y, NodeType type = NodeType::space);
    Node(const Node& node);
    Node(Node&& node);

    Node();

    Node& operator=(const Node& node);

    Node& operator=(Node&& node);

    bool is(NodeType& type) const;
    friend bool operator==(Node rhs, Node lhs);
    friend bool operator!=(Node rhs, Node lhs);

    ~Node();
};


#endif //SNAKE_PLUSPLUS_NODE_H
