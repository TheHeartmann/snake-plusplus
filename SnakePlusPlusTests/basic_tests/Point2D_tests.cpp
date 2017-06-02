//
// Created by clement on 10/05/17.
//

#include "gtest/gtest.h"
#include "board/grid/Point2D.h"


class Point2D_test : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    Point2D_test() : Test() {
        point2D = std::make_unique<Point2D>(30.5, 20.6);
    }


    virtual ~Point2D_test() {
    }

    std::unique_ptr<Point2D> point2D;
};

TEST_F(Point2D_test, isInsideSquareTest) {
    bool boundaryCheck = point2D->isInsideSquare(0, 0, 31, 21);
    bool badBoundaryCheck = point2D->isInsideSquare(0, 0, 30, 20);

    EXPECT_EQ(boundaryCheck, true);
    EXPECT_TRUE(boundaryCheck);
    EXPECT_FALSE(badBoundaryCheck);
}
