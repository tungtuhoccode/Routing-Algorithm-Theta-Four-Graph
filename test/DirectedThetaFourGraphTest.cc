#include "../include/ThetaFourVertex.h"
#include "../include/DirectedThetaFourGraph.h"
#include "gtest/gtest.h"


/*

Example test 

(1, 3)
(4, 7)
(8, 2)
(3, 6)
(7, 1)
(2, 8)
(5, 9)
(9, 5)
(6, 4)
(10, 11)

*/

//GetVertex
TEST(DirectedThetaFourGraphTest, GetVertexCorrectly){
    vector<ThetaFourVertex> vertices;
    ThetaFourVertex v1(1,3);
    ThetaFourVertex v2(4,7);
    ThetaFourVertex v3(8,2);

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);

    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    EXPECT_TRUE(graph.getVertex(1,3)->equals(1,3));
    EXPECT_FALSE(graph.getVertex(1,3)->equals(3,1));
    EXPECT_FALSE(graph.getVertex(1,3)->equals(1,1));
    EXPECT_FALSE(graph.getVertex(1,3)->equals(3,3));
    EXPECT_FALSE(graph.getVertex(1,3)->equals(5,10));
}

//SetNeighbor
TEST(DirectedThetaFourGraphTest, SetSimpleNeighborCorrectly) {
    //initilization of vertices list
    vector<ThetaFourVertex> vertices;
    int verticesXY[10][2] = {
        {1, 3},
        {4, 7},
        {8, 2},
        {3, 6},
        {7, 1},
        {2, 8},
        {5, 9},
        {9, 5},
        {6, 4},
        {10, 11}
    };

    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    //construct graph using list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    //ASSERT

    EXPECT_TRUE(graph.setNeighborFor(graph.getVertex(3,6)));
    ThetaFourVertex *v1 = graph.getVertex(3,6);


    EXPECT_TRUE(v1->getNeighbor(0)->equals(1,3));
    EXPECT_TRUE(v1->getNeighbor(1)->equals(4,7));
    EXPECT_TRUE(v1->getNeighbor(2)->equals(2,8));
    EXPECT_TRUE(v1->getNeighbor(3)->equals(6,4));
}

TEST(DirectedThetaFourGraphTest, SetSimpleNeighborCorrectly) {
    //initilization of vertices list
    vector<ThetaFourVertex> vertices;
    int verticesXY[10][2] = {
        {1, 3},
        {4, 7},
        {8, 2},
        {3, 6},
        {7, 1},
        {2, 8},
        {5, 9},
        {9, 5},
        {6, 4},
        {10, 11}
    };

    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    //construct graph using list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    //ASSERT

    EXPECT_TRUE(graph.setNeighborFor(graph.getVertex(3,6)));
    ThetaFourVertex *v1 = graph.getVertex(3,6);

    EXPECT_TRUE(v1->getNeighbor(0)->equals(1,3));
    EXPECT_TRUE(v1->getNeighbor(1)->equals(4,7));
    EXPECT_TRUE(v1->getNeighbor(2)->equals(2,8));
    EXPECT_TRUE(v1->getNeighbor(3)->equals(6,4));
}

TEST(DirectedThetaFourGraphTest, SetComplexNeighborCorrectly) {
    //initilization of vertices list
    vector<ThetaFourVertex> vertices;
    int verticesXY[10][2] = {
        {1, 3},
        {4, 7},
        {8, 2},
        {3, 6},
        {7, 1},
        {2, 8},
        {5, 9},
        {9, 5},
        {6, 4},
        {10, 11}
    };

    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    //construct graph using list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    //ASSERT

    EXPECT_TRUE(graph.setNeighborFor(graph.getVertex(3,6)));
    ThetaFourVertex *v1 = graph.getVertex(3,6);

    EXPECT_TRUE(v1->getNeighbor(0)->equals(1,3));
    EXPECT_TRUE(v1->getNeighbor(1)->equals(4,7));
    EXPECT_TRUE(v1->getNeighbor(2)->equals(2,8));
    EXPECT_TRUE(v1->getNeighbor(3)->equals(6,4));
} 