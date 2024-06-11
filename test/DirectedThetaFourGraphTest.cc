#include "../include/ThetaFourVertex.h"
#include "../include/DirectedThetaFourGraph.h"
#include "gtest/gtest.h"

//get cone
TEST(DirectedThetaFourGraph, GetConeCorreclty){
    //initilization of vertices list
    vector<ThetaFourVertex> vertices;
    ThetaFourVertex v1(1, 3);
    ThetaFourVertex v2(4, 7);
    ThetaFourVertex v3(8, 2);
    ThetaFourVertex v4(3, 6);
    ThetaFourVertex v5(7, 1);
    ThetaFourVertex v6(2, 8);
    ThetaFourVertex v7(5, 9);
    ThetaFourVertex v8(9, 5);
    ThetaFourVertex v9(6, 4);
    ThetaFourVertex v10(10, 11);

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
    vertices.push_back(v5);
    vertices.push_back(v6);
    vertices.push_back(v7);
    vertices.push_back(v8);
    vertices.push_back(v9);
    vertices.push_back(v10);


    //construct graph using list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    //ASSERT
    
    EXPECT_EQ(graph.getCone(v2, v9), 0);
    EXPECT_EQ(graph.getCone(v2, v7), 1);
    EXPECT_EQ(graph.getCone(v2, v6), 2);
    EXPECT_EQ(graph.getCone(v2, v4), 3);

    EXPECT_EQ(graph.getCone(v2, v1), 3);
    EXPECT_EQ(graph.getCone(v2, v3), 0);
    EXPECT_EQ(graph.getCone(v2, v5), 0);
    EXPECT_EQ(graph.getCone(v2, v8), 0);
    EXPECT_EQ(graph.getCone(v2, v10), 1);
}

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

    EXPECT_TRUE(graph.setNeighborsFor(graph.getVertex(3,6)));
    ThetaFourVertex *v1 = graph.getVertex(3,6);

    EXPECT_TRUE(v1->getNeighbor(0)->equals(6,4));
    EXPECT_TRUE(v1->getNeighbor(1)->equals(4,7));
    EXPECT_TRUE(v1->getNeighbor(2)->equals(2,8));
    EXPECT_TRUE(v1->getNeighbor(3)->equals(1,3));
}

TEST(DirectedThetaFourGraphTest, SetComplexNeighborCorrectly) {
    //initilization of vertices list
    vector<ThetaFourVertex> vertices;
    int verticesXY[10][2] = {
        {2, 8},
        {5, 9},
        {9, 5},
        {8, 2},
        {3, 6},
        {1, 3},
        {4, 7},
        {7, 1},
        {6, 4},
        {10, 11}
    };

    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    //construct graph using list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    //ASSERT
    ThetaFourVertex *v1 = graph.getVertex(6,4);
    EXPECT_TRUE(graph.setNeighborsFor(v1));


    EXPECT_TRUE(v1->getNeighbor(0)->equals(8,2));
    EXPECT_TRUE(v1->getNeighbor(1)->equals(9,5) );
    EXPECT_TRUE(v1->getNeighbor(2)->equals(3,6) || v1->getNeighbor(2)->equals(4,7));
    EXPECT_TRUE(v1->getNeighbor(3)->equals(1,3));
}

//graph constructor
TEST (DirectedThetaFourGraph, GraphConstructorRunCorrectly){
    //initilization of vertices list
    vector<ThetaFourVertex> vertices;
    int verticesXY[10][2] = {
        {2, 8},
        {5, 9},
        {9, 5},
        {8, 2},
        {3, 6},
        {1, 3},
        {4, 7},
        {7, 1},
        {6, 4},
        {10, 11}
    };

    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    //construct graph using list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    //(1,3)
    EXPECT_TRUE(graph.getVertex(1,3)->getNeighbor(0)->equals(7,1));
    EXPECT_TRUE(graph.getVertex(1,3)->getNeighbor(1)->equals(3,6));
    EXPECT_TRUE(graph.getVertex(1,3)->getNeighbor(2) == NULL);
    EXPECT_TRUE(graph.getVertex(1,3)->getNeighbor(3) == NULL);

    EXPECT_TRUE(
        graph.getVertex(2,8)->getNeighbor(0)->equals(3,6) ||
        graph.getVertex(2,8)->getNeighbor(0)->equals(4,7)
    );

    //(2,8)
    EXPECT_TRUE(graph.getVertex(2,8)->getNeighbor(1)->equals(5,9));
    EXPECT_TRUE(graph.getVertex(2,8)->getNeighbor(2) == NULL);
    EXPECT_TRUE(graph.getVertex(2,8)->getNeighbor(3)->equals(1,3));

     EXPECT_TRUE(
        graph.getVertex(2,8)->getNeighbor(0)->equals(3,6) ||
        graph.getVertex(2,8)->getNeighbor(0)->equals(4,7)
    );

    //(5,9)
    EXPECT_TRUE(graph.getVertex(5,9)->getNeighbor(0)->equals(6,4));
    EXPECT_TRUE(graph.getVertex(5,9)->getNeighbor(1)->equals(10,11));
    EXPECT_TRUE(graph.getVertex(5,9)->getNeighbor(2) == NULL);
    EXPECT_TRUE(graph.getVertex(5,9)->getNeighbor(3)->equals(4,7) );
    




}