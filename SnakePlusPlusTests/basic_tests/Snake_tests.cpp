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

        shared_ptr<Node> head = make_shared<Node>(0,0,type);
        shared_ptr<Node> body1 = make_shared<Node>(0,1,type);
        shared_ptr<Node> body2 = make_shared<Node>(0,2,type);
        shared_ptr<Node> tail = make_shared<Node>(0,3,type);

        list<shared_ptr<Node>> bodyList = {head, body1, body2, tail};
        
        testSnake = new Snake_new(bodyList);
	    originalSnake = new Snake_new(bodyList);
        lengthOriginal = testSnake->getLength();
        downVector = Vector2D{0,1};
	    auto headPtr = testSnake->getHead().get();
        resultNode = *headPtr + downVector;
	    resultPointer = make_shared<Node>(resultNode.grid_x, resultNode.grid_y);
    }

    virtual ~Snake_tests() {

    }

    Snake_new *testSnake;
	Snake_new *originalSnake;

    ulong lengthOriginal;
    Vector2D downVector = Vector2D(0, 0);
    Node resultNode;
	shared_ptr<Node> resultPointer;
};

TEST_F(Snake_tests, snakeMove_test){
	EXPECT_TRUE(testSnake->getHead() == originalSnake->getHead());
//	EXPECT_TRUE(testSnake == originalSnake);

    testSnake->move(resultPointer);
    auto lengthAfterMove = testSnake->getLength();

    EXPECT_EQ(lengthOriginal, lengthAfterMove);
	EXPECT_FALSE(testSnake->getHead() == originalSnake->getHead());
}

TEST_F(Snake_tests, snakeGrow_tests){
	EXPECT_TRUE(testSnake->getHead() == originalSnake->getHead());
	EXPECT_TRUE(testSnake->getTail() == originalSnake->getTail());


	testSnake->grow(resultPointer);
    auto lengthAfterGrow = testSnake->getLength();

    EXPECT_NE(lengthOriginal, lengthAfterGrow);
    EXPECT_EQ(lengthOriginal+1, lengthAfterGrow);
	EXPECT_FALSE(testSnake == originalSnake);
	EXPECT_FALSE(testSnake->getHead() == originalSnake->getHead());
	EXPECT_TRUE(testSnake->getTail() == originalSnake->getTail());
}