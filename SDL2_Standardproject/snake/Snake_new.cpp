//
// Created by clement on 02/06/17.
//

#include <iostream>
#include "Snake_new.h"


Snake_new::Snake_new() {}

Snake_new::~Snake_new() {}

Node Snake_new::getHead() const{
	return body.front();
}

Node Snake_new::getTail() const {
	return body.back();
}


void Snake_new::move(Node& newHeadPosition) {

	body.push_front(newHeadPosition);
	body.pop_back();
}

void Snake_new::grow(Node& newHeadPosition) {
	body.push_front(newHeadPosition);
}

Snake_new::Snake_new(list<Node> _body) {
	for (auto b: _body)
		body.push_back(b);

}

Snake_new::Snake_new(initializer_list<Node> _body) {
	for (auto b: _body)
		body.push_back(b);
}

list <Node> Snake_new::getBody() const {
	return body;
}
//
//bool Snake_new::operator==(const Snake_new &rhs) const {
//	if (this->getLength() != rhs.getLength()) return false;
//	auto thisIterator = this->getBody().begin();
//	auto rhsIterator = rhs.getBody().begin();
//
//	while (thisIterator != this->getBody().end()){
//		auto thisNode = thisIterator->get();
//		auto rhsNode = rhsIterator->get();
//		if (thisNode->hasSamePosition(*rhsNode)) {
//			return false;
//		}
//		thisIterator++; rhsIterator++;
//	}
//
//	return true;
//}
//
//bool Snake_new::operator!=(const Snake_new &rhs) const {
//	return !(*this == rhs);
//}
