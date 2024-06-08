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

TEST (DISABLE_ThetaFourVertexConstructor, CopyConstructorWithNeighbor){
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
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    ThetaFourVertex newVertex = ThetaFourVertex(Point(22,-11));
    vertex.setNeighbor(1, newVertex.getPoint());

    double distance = vertex.getPoint().distanceTo(newVertex.getPoint());

    EXPECT_EQ(get<0>(vertex.getNeighbor(1)).getX(), 22);
    EXPECT_EQ(get<0>(vertex.getNeighbor(1)).getY(), -11);

    EXPECT_DOUBLE_EQ(get<1>(vertex.getNeighbor(1)), distance);

}

// setNeighbor() functions
TEST (DISABLE_ThetaFourVertexsetNeighbor, setNeighborCorrectly){
    ThetaFourVertex vertex = ThetaFourVertex(10,1);
    vertex.setNeighbor(1, Point(20, 1));
    // EXPECT_EQ(vertex.getNeighbor(1).getX(), 20);
    // EXPECT_EQ(vertex.getNeighbor(1).getY(), 1);
}