#include "../include/ThetaFourVertex.h"
#include "../include/DijkstraAlgorithm.h"

#include <gtest/gtest.h>

//equals(int x, int y)
TEST(ThetaFourVertex, EqualsCheckCorrectly){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);
    EXPECT_TRUE(vertex.equals(10,1));

    EXPECT_FALSE(vertex.equals(5,1));
    EXPECT_FALSE(vertex.equals(1,10));
    EXPECT_FALSE(vertex.equals(10,5));
    EXPECT_FALSE(vertex.equals(6,10));
}

TEST(ThetaFourVertex, EqualsCheckUninitilized){
    ThetaFourVertex vertex;
    EXPECT_THROW (vertex.equals(1,5), std::logic_error); 
}

TEST(ThetaFourVertex, CorrectID){
    ThetaFourVertex::resetID();

    ThetaFourVertex vertex0 = ThetaFourVertex(10, 1);
    ThetaFourVertex vertex1 = ThetaFourVertex(10, 1);
    ThetaFourVertex vertex2 = ThetaFourVertex(10, 1);
    ThetaFourVertex vertex3 = ThetaFourVertex(10, 1);
    ThetaFourVertex vertex4 = ThetaFourVertex(10, 1);
    ThetaFourVertex vertex5 = ThetaFourVertex(10, 1);

    EXPECT_EQ(vertex0.getId(), 0);
    EXPECT_EQ(vertex1.getId(), 1);
    EXPECT_EQ(vertex2.getId(), 2);
    EXPECT_EQ(vertex3.getId(), 3);
    EXPECT_EQ(vertex4.getId(), 4);
    EXPECT_EQ(vertex5.getId(), 5);
}

TEST(ThetaFourVertex, CopyConstructorCorrectID){
    ThetaFourVertex::resetID();

    ThetaFourVertex vertex0 = ThetaFourVertex(10, 1);
    ThetaFourVertex vertex1 = ThetaFourVertex(vertex0);



    EXPECT_EQ(vertex0.getId(), vertex1.getId());
}


// setNeighbor(int coneI, ThetaFourVertex* vertex)
TEST(ThetaFourVertex, SetNeighborCorrectly){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);
    ThetaFourVertex neightborVertex = ThetaFourVertex(30, 11);
    vertex.setNeighbor(0, &neightborVertex);

    EXPECT_EQ(vertex.getNeighbor(0), &neightborVertex);
    EXPECT_EQ(vertex.getNeighbor(0)->getX(), neightborVertex.getX());
    EXPECT_EQ(vertex.getNeighbor(0)->getY(), neightborVertex.getY());
}

TEST(ThetaFourVertex, SetNeighborOutOfBound){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);
    ThetaFourVertex neightborVertex = ThetaFourVertex(30, 11);

    EXPECT_THROW(vertex.setNeighbor(4, &neightborVertex), std::invalid_argument);
    EXPECT_THROW(vertex.setNeighbor(-1, &neightborVertex), std::invalid_argument);
}

// getNeightbor()
TEST(ThetaFourVertex, GetNeightborInvalidIndex){
    ThetaFourVertex vertex = ThetaFourVertex();

    EXPECT_THROW(vertex.getNeighbor(-1), std::invalid_argument);
    EXPECT_THROW(vertex.getNeighbor(4), std::invalid_argument);
}

// Default Constructor
TEST(ThetaFourVertex, DefaultConstructor){
    ThetaFourVertex vertex = ThetaFourVertex();

    EXPECT_FALSE(vertex.getX().has_value());
    EXPECT_FALSE(vertex.getY().has_value());

    EXPECT_EQ( vertex.getNeighbor(0), nullptr );
}

// ThetaFourVertex(int x, int y)
TEST(ThetaFourVertex, IntegerCoordinateConstructor){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);

    EXPECT_TRUE(vertex.getX().has_value() == true);
    EXPECT_TRUE(vertex.getY().has_value() == true);
    
    EXPECT_TRUE(vertex.getX() == 10);
    EXPECT_TRUE(vertex.getY() == 1);

    EXPECT_TRUE( vertex.getNeighbor(0) == nullptr);
}

// Copy constructor
TEST(ThetaFourVertex, CopyConstructorNoNeighbor){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);
    ThetaFourVertex copiedVertex = ThetaFourVertex(vertex);

    EXPECT_TRUE(copiedVertex.getX() == vertex.getX());
    EXPECT_TRUE(copiedVertex.getY() == vertex.getY());

    EXPECT_TRUE(copiedVertex.getX().has_value() == true);
    EXPECT_TRUE(copiedVertex.getY().has_value() == true);

    EXPECT_TRUE( copiedVertex.getNeighbor(0) == vertex.getNeighbor(1));
}

TEST(ThetaFourVertex, getIntXGetIntY){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);

    EXPECT_TRUE(vertex.getIntX() == 10);
    EXPECT_TRUE(vertex.getIntY() == 1);
}

TEST(ThetaFourVertex, CopyConstructorWithNeighbor1){
    ThetaFourVertex vertex = ThetaFourVertex(10, 1);
    ThetaFourVertex neightborVertex = ThetaFourVertex(30, 11);
    vertex.setNeighbor(0, &neightborVertex);

    EXPECT_EQ(vertex.getNeighbor(0), &neightborVertex);

    ThetaFourVertex copiedVertex = ThetaFourVertex(vertex);

    EXPECT_TRUE(copiedVertex.getNeighbor(0) == &neightborVertex);
    EXPECT_TRUE(copiedVertex.getNeighbor(0)->getX() == neightborVertex.getX());
    EXPECT_TRUE(copiedVertex.getNeighbor(0)->getY() == neightborVertex.getY());

    EXPECT_TRUE(copiedVertex.getNeighbor(1) == vertex.getNeighbor(1));
    EXPECT_TRUE(copiedVertex.getNeighbor(2) == vertex.getNeighbor(2));
    EXPECT_TRUE(copiedVertex.getNeighbor(3) == vertex.getNeighbor(3));
}

TEST(ThetaFourVertex, DijkstraAlgorithmInitialTest){
       // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[10][2] = {
        {1, 3},
        {-4, 7},
        {8, -2},
        {3, 6},
        {-7, 1},
        {2, -8},
        {-5, 9},
        {9, -5},
        {6, 4},
        {-10, 11}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    DijkstraAlgorithm dijkstra; 

    cout << dijkstra.shortestPath(1, 3, -10, 11, graph) << endl;
}
