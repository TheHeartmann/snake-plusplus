//
// Created by clement on 02/06/17.
//

#include <gtest/gtest.h>
#include <Snake_new.h>

class Snake_tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    Snake_tests() : Test() {
        NodeType type = NodeType::snake;
        unique_ptr<Node> tail = make_unique<Node>(0,0,type);
        unique_ptr<Node> body1 = make_unique<Node>(0,1,type);
        unique_ptr<Node> head = make_unique<Node>(0,2,type);

        auto bodyList = { tail, body1, head};

        testSnake = new Snake_new(bodyList);
    }

    virtual ~Snake_tests() {

    }

    Snake_new *testSnake;

};

TEST_F(Snake_tests, SnakeMove_test){

}