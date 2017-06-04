//
// Created by clement on 02/06/17.
//

//#include <gtest/gtest.h>
#include "gtest/gtest.h"
#include <snake/Snake.h>

class Snake_tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    Snake_tests() : Test() {
        Node head (0,0);
        Node body1 (0,1);
        Node body2 (0,2);
        Node tail (0,3);

        list<Node> bodyList = {head, body1, body2, tail};
        
        testSnake = new Snake(bodyList);
	    originalSnake = new Snake(bodyList);
        lengthOriginal = testSnake->getLength();
//        downVector = Vector2D{0,1};
	    auto resultNode = testSnake->getHead();
    }

    virtual ~Snake_tests() {

    }

    Snake *testSnake;
	Snake *originalSnake;

    ulong lengthOriginal;
    Vector2D downVector = Vector2D(0, 1);
    Node resultNode;
};

TEST_F(Snake_tests, snakeMove_test){
	EXPECT_TRUE(testSnake->getHead() == originalSnake->getHead());
//	EXPECT_TRUE(testSnake == originalSnake);

    testSnake->move(resultNode);
    auto lengthAfterMove = testSnake->getLength();

    EXPECT_EQ(lengthOriginal, lengthAfterMove);
	EXPECT_FALSE(testSnake->getHead() == originalSnake->getHead());
}

TEST_F(Snake_tests, snakeGrow_tests){
	EXPECT_TRUE(testSnake->getHead() == originalSnake->getHead());
	EXPECT_TRUE(testSnake->getTail() == originalSnake->getTail());


	testSnake->grow(resultNode);
    auto lengthAfterGrow = testSnake->getLength();

    EXPECT_NE(lengthOriginal, lengthAfterGrow);
    EXPECT_EQ(lengthOriginal+1, lengthAfterGrow);
	EXPECT_FALSE(testSnake == originalSnake);
	EXPECT_FALSE(testSnake->getHead() == originalSnake->getHead());
	EXPECT_TRUE(testSnake->getTail() == originalSnake->getTail());
}