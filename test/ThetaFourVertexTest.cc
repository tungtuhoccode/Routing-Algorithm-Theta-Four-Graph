#include "../include/ThetaFourVertex.h"
#include <gtest/gtest.h>

// Constructor(int x, int y)
TEST (ThetaFourVertexConstructor, CoordinateInputConstructor){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);

    EXPECT_EQ(vertex.getPoint().getX(), 10);
    EXPECT_EQ(vertex.getPoint().getY(), 1);
}

// Constructor(Point point)
TEST (ThetaFourVertexConstructor, PointInputConstructor){
    Point point = Point(10,1);
    ThetaFourVertex vertex = ThetaFourVertex(point);

    EXPECT_EQ(vertex.getPoint().getX(), 10);
    EXPECT_EQ(vertex.getPoint().getY(), 1);
}

// Copy Constructor(const ThetaFourVertex& vertex)
TEST (ThetaFourVertexConstructor, CopyConstructorNoNeighbor){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    ThetaFourVertex newVertex = ThetaFourVertex(vertex);

    EXPECT_EQ(newVertex.getPoint().getX(), 10);
    EXPECT_EQ(newVertex.getPoint().getY(), 1);
}

TEST (ThetaFourVertexConstructor, CopyConstructorWithNeighbor){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    vertex.setNeighbor(1, Point(20, 1));
    ThetaFourVertex newVertex = ThetaFourVertex(vertex);

    EXPECT_EQ(newVertex.getPoint().getX(), 10);
    EXPECT_EQ(newVertex.getPoint().getY(), 1);
    // EXPECT_EQ(newVertex.getNeighbor(1).getX(), 20);
    // EXPECT_EQ(newVertex.getNeighbor(1).getY(), 1);
}

// getPoint() functions
TEST (ThetaFourVertexGetPoint, GetPointCorrectly){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    
    EXPECT_EQ(vertex.getPoint().getX(), 10);
    EXPECT_EQ(vertex.getPoint().getY(), 1);
}

// getNeighbor() functions
TEST (ThetaFourVertexgetNeighbor, getNeighborCorrectly){
    //Arrange
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    ThetaFourVertex newVertex = ThetaFourVertex(Point(22,-11));
    
    //Act
    vertex.setNeighbor(1, newVertex.getPoint());

    double distance = vertex.getPoint().distanceTo(newVertex.getPoint());

    Point neighborPoint = vertex.getNeighbor(1).first;

    //Assert
    EXPECT_EQ(vertex.getNeighbor(1).first.getX(), 22);
    EXPECT_EQ(vertex.getNeighbor(1).first.getY(), -11);

    EXPECT_DOUBLE_EQ(vertex.getNeighbor(1).second, distance);
}

// ThetaFourVertex::distanceTo() functions
TEST (ThetaFourVertexDistanceTo, AllPositive){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    ThetaFourVertex newVertex = ThetaFourVertex(Point(20,1));

    ASSERT_EQ(vertex.distanceTo(newVertex), 10);
}

TEST (ThetaFourVertexDistanceTo, PositiveNegative){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    ThetaFourVertex newVertex = ThetaFourVertex(Point(22,-11));

    ASSERT_NEAR(vertex.distanceTo(newVertex), 16.97056, 0.01);
}

TEST (ThetaFourVertexDistanceTo, AllNegative){
    ThetaFourVertex vertex = ThetaFourVertex(-10,-1);
    ThetaFourVertex newVertex = ThetaFourVertex(Point(-21, -11));

    ASSERT_NEAR(vertex.distanceTo(newVertex), 14.8660, 0.01);
}

// setNeighbor() functions
TEST (ThetaFourVertexsetNeighbor, setNeighborCorrectly){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    ThetaFourVertex newVertex = ThetaFourVertex(Point(20,1));

    vertex.setNeighbor(1, newVertex.getPoint());

    Point neighborPoint = vertex.getNeighbor(1).first;
   
    double distance = vertex.distanceTo(newVertex);

    EXPECT_EQ(neighborPoint.getX(), 20);
    EXPECT_EQ(neighborPoint.getY(), 1);

    EXPECT_DOUBLE_EQ(vertex.getNeighbor(1).second, distance);
}