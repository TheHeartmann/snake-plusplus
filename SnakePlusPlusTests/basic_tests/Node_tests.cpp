//
// Created by clement on 01/06/17.
//

#include "gtest/gtest.h"
#include "board/Node.h"

class Node_tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    Node node1{1, 2, NodeType::apple};
    Node node2{1, 2, NodeType::apple};
    Node node3{2, 2, NodeType::apple};
    Node node4{1, 2, NodeType::snake};


    Node_tests() : Test() {

    }

    virtual ~Node_tests() {
    }

};

TEST_F(Node_tests, OverLoadedEqualOperator_test) {

    EXPECT_EQ(node1, node2);
    EXPECT_NE(node1, node3);
    EXPECT_NE(node1, node4);
}

TEST_F(Node_tests, NodeIsOfNodeType_test) {

    EXPECT_TRUE(node1.is(node2.type));
    EXPECT_TRUE(node1.is(node3.type));
    EXPECT_FALSE(node1.is(node4.type));

}

TEST_F(Node_tests, copyConstructor_Tests) {
    Node receivingNode = node1;
    auto refReceive = &receivingNode;
    auto refNode1 = &node1;
    EXPECT_FALSE(refReceive == refNode1);
}

TEST_F(Node_tests, vectorArithmetics_Tests){
    auto rightVector = Vector2D{1,0};
    auto newNode = node2+rightVector;
    EXPECT_TRUE(newNode.hasSamePosition(node3));
}