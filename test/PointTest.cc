#include "../include/Point.h"
#include <gtest/gtest.h>

// PointTest::print() functions
TEST (PointPrintTest, PrintFormatCorrectly){
    Point point = Point(10,1);
    ASSERT_EQ(point.print(), "(10, 1)");
}

// getX() functions
TEST (PointGetX, TestCase1){
    Point point = Point(10,1);
    ASSERT_EQ(point.getX(), 10);
}

// getY() functions
TEST (PointGetY, Test1){
    Point point = Point(10,1);
    ASSERT_EQ(point.getY(), 1);
}

// setX() functions
TEST (PointSetX, Test1){
    Point point = Point(10,1);
    point.setX(20);
    ASSERT_EQ(point.getX(), 20);
}

// setY() functions
TEST (PointSetY, Test1){
    Point point = Point(10,1);
    point.setY(20);
    ASSERT_EQ(point.getY(), 20);
}


// copy constructor
TEST (PointCopyConstructor, CopyCorrectly){
    Point point = Point(10,1);
    Point newPoint = Point(point);
    EXPECT_EQ(point.getX(), newPoint.getX());
    EXPECT_EQ(point.getY(), newPoint.getY());
}

// distanceTo() functions
TEST (PointDistanceTo, AllPositive){
    Point point1 = Point(10,1);
    Point point2 = Point(20, 1);
    ASSERT_EQ(point1.distanceTo(point2), 10);
}

TEST (PointDistanceTo, PositiveNegative){
    Point point1 = Point(10,1);
    Point point2 = Point(22, -11);

    ASSERT_NEAR(point1.distanceTo(point2), 16.97056, 0.01);
}

TEST (PointDistanceTo, AllNegative){
    Point point1 = Point(-10,-1);
    Point point2 = Point(-21, -11);
    ASSERT_NEAR(point1.distanceTo(point2), 14.8660, 0.01);
}