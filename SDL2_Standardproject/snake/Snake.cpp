//
// Created by clement on 02/06/17.
//

#include <iostream>
#include "Snake.h"


Snake::Snake() {}

Snake::~Snake() {}

Node Snake::getHead() const{
	return body.front();
}

Node Snake::getTail() const {
	return body.back();
}


void Snake::move(Node& newHeadPosition) {

	body.push_front(newHeadPosition);
	body.pop_back();
}

void Snake::grow(Node& newHeadPosition) {
	body.push_front(newHeadPosition);
}

Snake::Snake(list<Node> _body) {
	for (auto b: _body)
		body.push_back(b);

}

Snake::Snake(initializer_list<Node> _body) {
	for (auto b: _body)
		body.push_back(b);
}

list <Node> Snake::getBody() const {
	return body;
}