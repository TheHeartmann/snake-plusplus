//
// Created by clement on 02/06/17.
//

#include <iostream>
#include "Snake_new.h"

Snake_new::Snake_new(initializer_list<Node> _body) {
    //body = new list<Node>(_body);
    for(auto& b: _body)
        body.push_back(b);
}

Snake_new::Snake_new(list<Node> _body) {
    cout << "Creating snake..." << endl;
    for(auto b: _body)
        body.push_back(b);
    cout << "Snake created." << endl;
}

Snake_new::~Snake_new() {
/*    delete body;*/
}

Node Snake_new::getHead() const {
    /*return body->front();*/
    return body.front();
}

Node Snake_new::getTail() const {
    /*return body->back(); */
    return body.back();
}


void Snake_new::move(Node newHeadPosition) {
/*
    body->push_front(newHeadPosition);
    body->pop_back();
*/
    body.push_front(newHeadPosition);
    body.pop_back();
}

void Snake_new::grow(Node newHeadPosition) {
    /*body->push_front(newHeadPosition);
    */body.push_front(newHeadPosition);
}


