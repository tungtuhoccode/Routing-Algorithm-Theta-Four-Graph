#include "../include/RoutingAlgorithm.h"
#include "DirectedThetaFourGraph.h"

string RoutingAlgorithm::bruteForce(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph){
    if(graph.getVertex(xu,yu) == NULL || graph.getVertex(xt,yt) == NULL ) return "Invalid input!";

    graph.getVertex(x1,y1);
    graph.getCone()

}

bool RoutingAlgorithm::clean(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, byte d){
    int u_X = u->getX().value();
    int u_Y = u->getY().value();

    int t_X = u->getX().value();
    int t_Y = u->getY().value();
    

}