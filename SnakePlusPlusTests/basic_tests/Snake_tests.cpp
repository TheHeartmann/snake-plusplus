//
// Created by clement on 02/06/17.
//

//#include <gtest/gtest.h>
#include "gtest/gtest.h"
#include <snake/Snake_new.h>

class Snake_tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    Snake_tests() : Test() {
        NodeType type = NodeType::snake;
//        unique_ptr<Node> tail = make_unique<Node>(0,0,type);
//        unique_ptr<Node> body1 = make_unique<Node>(0,1,type);
//        unique_ptr<Node> head = make_unique<Node>(0,2,type);
//
//
//
//        auto bodyList = { tail, body1, head};

        Node tailNode{0,0,type};
        Node bodyNode1{0,1, type};
        Node bodyNode2{0,2, type};
        Node headNode{0,3, type};

        auto bodyListTwo = {headNode, bodyNode1, bodyNode2, tailNode};

//        testSnake = new Snake_new(bodyList);
        testSnake = new Snake_new(bodyListTwo);
    }

    virtual ~Snake_tests() {

    }

    Snake_new *testSnake;
};

TEST_F(Snake_tests, SnakeMove_test){

    auto lengthBeforeMove = testSnake->getLength();

//  Get node: game manager's responsibility
    auto down = Vector2D{0,1};
    auto newHeadPosition = testSnake->getHead() + down;

//  Move snake
    testSnake->move(newHeadPosition);
    EXPECT_EQ(lengthBeforeMove, testSnake->getLength());
}