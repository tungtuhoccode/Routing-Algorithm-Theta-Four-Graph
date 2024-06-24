#include "../include/ThetaFourVertex.h"
#include "../include/DirectedThetaFourGraph.h"
#include "../include/RoutingAlgorithm.h"
#include "gtest/gtest.h"
//GREEDY ROUTING ONLY
TEST (GreedyRoutingOnly, AllPositive){
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

    RoutingAlgorithm algo;

    cout << algo.greedyRoutingOnly(v6.getX().value(), v6.getY().value(), v5.getX().value(), v5.getY().value(), graph) << endl;
}

TEST (GreedyRoutingOnly, PositiveAndNegative){
    // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[10][2] = {
        {1, 3},
        {-4, 7},
        {12, -2},
        {3, 6},
        {-7, 1},
        {2, -10},
        {-5, 10},
        {8, -6},
        {6, 4},
        {-10, 11}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    RoutingAlgorithm algo;

    cout << algo.greedyRoutingOnly(-10, 11, 8, -6, graph) << endl;
}

// getDiagonal
TEST (GetDiagonal, GetDiagonalCorrectly){
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

    RoutingAlgorithm algo;

    EXPECT_EQ(algo.getClosestDiagonal(graph.getVertex(2,8), graph.getVertex(10,11), graph), 1);
    EXPECT_EQ(algo.getClosestDiagonal(graph.getVertex(3,6), graph.getVertex(9,5), graph ), -1);

    EXPECT_EQ(algo.getClosestDiagonal(graph.getVertex(8,2), graph.getVertex(3,6), graph), -1);
    EXPECT_EQ(algo.getClosestDiagonal(graph.getVertex(10,11), graph.getVertex(3,6), graph ), 1);
}

// isClean
TEST (isClean, PositiveAndNegativeVertices){
    // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[10][2] = {
        {1, 3},
        {-4, 7},
        {12, -2},
        {3, 6},
        {-7, 1},
        {2, -10},
        {-5, 10},
        {8, -6},
        {6, 4},
        {-10, 11}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    RoutingAlgorithm algo;

    ASSERT_TRUE(algo.isClean(graph.getVertex(6,4), graph.getVertex(12,-2), graph, -1));
    ASSERT_FALSE(algo.isClean(graph.getVertex(1,3), graph.getVertex(12,-2), graph, -1));
    ASSERT_FALSE(algo.isClean(graph.getVertex(6,4), graph.getVertex(8,-6), graph, -1));
    ASSERT_TRUE(algo.isClean(graph.getVertex(1,3), graph.getVertex(8,-6), graph, -1));

    ASSERT_TRUE(algo.isClean(graph.getVertex(2,-10), graph.getVertex(6,4), graph, 1));
    ASSERT_FALSE(algo.isClean(graph.getVertex(-4,7), graph.getVertex(6,4), graph, 1));
    ASSERT_FALSE(algo.isClean(graph.getVertex(3,6), graph.getVertex(6,4), graph, 1));
    ASSERT_TRUE(algo.isClean(graph.getVertex(1,3), graph.getVertex(6,4), graph, 1));
}

// isClean
TEST (sweep, PositiveAndNegativeVertices){
    // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[10][2] = {
        {1, 3},
        {-4, 7},
        {12, -2},
        {3, 6},
        {-7, 1},
        {2, -10},
        {-5, 10},
        {8, -6},
        {6, 4},
        {-10, 11}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    RoutingAlgorithm algo;

    ASSERT_TRUE(algo.sweep(graph.getVertex(-4,7), graph.getVertex(6,4), graph, 1)->equals(3,6));
    ASSERT_TRUE(algo.sweep(graph.getVertex(3,6), graph.getVertex(6,4), graph, 1)->equals(6,4));
    ASSERT_TRUE(algo.sweep(graph.getVertex(1,3), graph.getVertex(12,-2), graph, -1)->equals(3,6));
    ASSERT_TRUE(algo.sweep(graph.getVertex(6,4), graph.getVertex(8,-6), graph, -1)->equals(1,3));
}

//GreedySweep algorithm
TEST (GreedySweepRouting, PositiveAndNegative){
    // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[10][2] = {
        {1, 3},
        {-4, 7},
        {12, -2},
        {3, 6},
        {-7, 1},
        {2, -10},
        {-5, 10},
        {8, -6},
        {6, 4},
        {-10, 11}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    RoutingAlgorithm algo;
    cout << algo.greedyRoutingOnly(-10, 11, 6, 4, graph) << endl;
    cout << algo.greedyRoutingOnly(-10, 11, 12, -2, graph) << endl;
    cout << algo.GreedySweepRouting(-10, 11, 6, 4, graph) << endl;
    cout << algo.GreedySweepRouting(-10, 11, 12, -2, graph) << endl;
}

TEST (RoutingOnlyReturnPath, PositiveAndNegative){
    // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[10][2] = {
        {1, 3},
        {-4, 7},
        {12, -2},
        {3, 6},
        {-7, 1},
        {2, -10},
        {-5, 10},
        {8, -6},
        {6, 4},
        {-10, 11}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 10; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    RoutingAlgorithm algo;
    vector<ThetaFourVertex> greedyOnlyPath = algo.greedyRoutingOnlyReturnPath(-10, 11, 6, 4, graph);
    string strPath = "";
    double pathLength = 0;

    strPath += greedyOnlyPath[0].print();

    for (int i = 1; i < greedyOnlyPath.size(); i++){
        strPath += greedyOnlyPath[i].print();
        pathLength += greedyOnlyPath[i].distanceTo(greedyOnlyPath[i-1]);
    }
    cout << "Path: " << strPath << endl;
    cout << "Path length: " << pathLength << endl;
}