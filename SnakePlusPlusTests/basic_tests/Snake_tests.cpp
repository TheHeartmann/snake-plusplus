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

        Node tail{0,0,type};
        Node body1{0,1, type};
        Node body2{0,2, type};
        Node head{0,3, type};

        auto bodyList = {head, body1, body2, tail};
        
        testSnake = new Snake_new(bodyList);
        lengthOriginal = testSnake->getLength();
        downVector = Vector2D{0,1};
        resultNode = testSnake->getHead() + downVector;
    }

    virtual ~Snake_tests() {

    }

    Snake_new *testSnake;

    ulong lengthOriginal;
    Vector2D downVector = Vector2D(0, 0);
    Node resultNode;
};

TEST_F(Snake_tests, snakeMove_test){
    testSnake->move(resultNode);
    auto lengthAfterMove = testSnake->getLength();
    EXPECT_EQ(lengthOriginal, lengthAfterMove);
}

TEST_F(Snake_tests, snakeGrow_tests){
    testSnake->grow(resultNode);
    auto lengthAfterGrow = testSnake->getLength();

    EXPECT_NE(lengthOriginal, lengthAfterGrow);
    EXPECT_EQ(lengthOriginal+1, lengthAfterGrow);
}