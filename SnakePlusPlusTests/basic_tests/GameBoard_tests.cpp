//
// Created by clement on 01/06/17.
//

#include <gtest/gtest.h>
#include <board/GameBoard.h>

class GameBoard_tests : public ::testing::Test {
protected:

    static void SetUpTestCase() {
        board = new GameBoard{30, 10};
    }

    virtual void TearDown() {
    }

    virtual void SetUp() {

    }

    static GameBoard *board;


public:

    GameBoard_tests() : Test() {
    }

    virtual ~GameBoard_tests() {}
};

GameBoard *GameBoard_tests::board = nullptr;


TEST_F(GameBoard_tests, initialiseBoard_test) {
    auto b = board->getBoard();

    Node firstNode = b[0][0];
    Node expected1{0, 0};
    auto type = NodeType::space;

    ASSERT_TRUE(firstNode.is(type));
    ASSERT_EQ(firstNode, expected1);

    Node nextnode = b[1][0];
    Node expected2{1, 0};
    ASSERT_EQ(nextnode, expected2);

}

TEST_F(GameBoard_tests, boardDestructor_test) {
    //testing destructor
    EXPECT_NO_THROW(
            {
                GameBoard testBoard;
            });
}

TEST_F(GameBoard_tests, boardUpdatePersistence_test) {
    auto newType = NodeType::snake;
    board->getBoard()[0][0] = {-1, -1, newType};

    auto testedNode = board->getBoard()[0][0];
    Node immediateComparison{-1, -1, newType};

    ASSERT_TRUE(testedNode.is(newType));
    ASSERT_EQ(testedNode, immediateComparison);
}

TEST_F(GameBoard_tests, boardUpdatePersistenceFollowUp_test) {
    auto newType = NodeType::snake;

    auto testedNode = board->getBoard()[0][0];
    Node persistedComparison{-1, -1, newType};

    ASSERT_TRUE(testedNode.is(newType));
    ASSERT_EQ(testedNode, persistedComparison);
}


