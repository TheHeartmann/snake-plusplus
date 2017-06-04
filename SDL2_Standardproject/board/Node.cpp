//
// Created by clement on 01/06/17.
//

#include "Node.h"

Node::Node() : Node{-1, -1} {}

Node::Node(int _grid_x, int _grid_y) : grid_x{_grid_x}, grid_y{_grid_y} {}

Node::Node(const Node &node) : grid_x{node.grid_x}, grid_y{node.grid_y} {}

Node::Node(Node &&node) : grid_x{0}, grid_y{0} {
    grid_x = node.grid_x;
    grid_y = node.grid_y;
    node.grid_x = 0;
    node.grid_y = 0;
}

Node::~Node() {}


Node &Node::operator=(const Node &node) {
    if (this != &node) {
        grid_x = node.grid_x;
        grid_y = node.grid_y;
    }
    return *this;
}

Node &Node::operator=(Node &&node) {
    grid_x = node.grid_x;
    grid_y = node.grid_y;
    return *this;
}

bool Node::operator==(const Node &rhs) const {
    return this->hasSamePosition(rhs);


}

bool Node::operator!=(const Node &rhs) const {
    return !(*this == rhs);
}


Node Node::operator+(Vector2D &rhs) const {
    auto x = this->grid_x + rhs.getX();
    auto y = this->grid_y + rhs.getY();

    return Node{x, y};
}

bool Node::hasSamePosition(const Node &rhs) const {
    return this->grid_x == rhs.grid_x &&
           this->grid_y == rhs.grid_y;
}

Vector2D Node::operator-(Node &target) const {
	auto x = target.grid_x - this->grid_x;
    auto y = target.grid_y - this->grid_y;

	return Vector2D{x, y};
}