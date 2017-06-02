//
// Created by clement on 02/06/17.
//

#include "Snake_new.h"

Snake_new::Snake_new(initializer_list<unique_ptr<Node>> _body) {
    body = new list<unique_ptr<Node>>(_body);
}

Snake_new::~Snake_new() {
    delete body;
}

unique_ptr<Node> Snake_new::getHead() const { return body->front(); }

unique_ptr<Node> Snake_new::getTail() const { return body->back(); }

void Snake_new::move(unique_ptr<Node> const newHeadPosition) {
    body->push_front(newHeadPosition);
    body->pop_back();
}

void Snake_new::grow(const unique_ptr<Node> newHeadPosition) {
    body->push_front(newHeadPosition);
}