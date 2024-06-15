#include "../include/ThetaFourVertex.h"
#include "../include/DirectedThetaFourGraph.h"
#include "../include/RoutingAlgorithm.h"
#include "gtest/gtest.h"

TEST (GreedyRoutingOnly, TestGraph1){
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
