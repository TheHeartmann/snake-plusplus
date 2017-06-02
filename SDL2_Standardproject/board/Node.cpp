//
// Created by clement on 01/06/17.
//

#include "Node.h"

Node::Node() : Node{-1, -1} {}

Node::Node(int _grid_x, int _grid_y, NodeType _type) : grid_x{_grid_x}, grid_y{_grid_y}, type{_type} {}

Node::Node(const Node &node) : grid_x{node.grid_x}, grid_y{node.grid_y}, type{node.type} {

}

Node::Node(Node &&node) : grid_x{0}, grid_y{0} {
    grid_x = node.grid_x;
    grid_y = node.grid_y;
    type = node.type;
    node.grid_x = 0;
    node.grid_y = 0;
}

Node &Node::operator=(const Node &node) {
    if (this != &node) {
        grid_x = node.grid_x;
        grid_y = node.grid_y;
        type = node.type;
    }
    return *this;
}

Node &Node::operator=(Node &&node) {
    grid_x = node.grid_x;
    grid_y = node.grid_y;
    type = node.type;
    return *this;
}

/*
bool operator==(const Node& lhs, const Node& rhs) {
    return lhs.is(rhs.type) &&
           lhs.grid_x == rhs.grid_x &&
           lhs.grid_y == rhs.grid_y;
}

bool operator!=(const Node& lhs, const Node& rhs) {
    return !lhs.is(rhs.type) ||
           lhs.grid_x != rhs.grid_x ||
           lhs.grid_y != rhs.grid_y;
}
*/
bool Node::operator==(const Node &rhs) const {
    return this->is(rhs.type) &&
           this->grid_x == rhs.grid_x &&
           this->grid_y == rhs.grid_y;
}

bool Node::operator!=(const Node &rhs) const {
    return !(*this == rhs);
}


bool Node::is(const NodeType &_type) const {
    return type == _type;
}

Node::~Node() {

}

Node Node::operator+(Vector2D &rhs) {
    auto x = this->grid_x + rhs.getX();
    auto y = this->grid_y + rhs.getY();

    return Node{x, y};
}

