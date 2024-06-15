#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"

string RoutingAlgorithm::greedyRoutingOnly(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph){
    if(graph.getVertex(xu,yu) == NULL || graph.getVertex(xt,yt) == NULL ) return "Invalid input!";
    
    string path = "";
    ThetaFourVertex *currentVertex = graph.getVertex(xu, yu);
    ThetaFourVertex *targetVertex = graph.getVertex(xt, yt);

    
    while (true){
        path += currentVertex->print(); 
        
        if(currentVertex->equals(xt,yt)) break;

        currentVertex = greedy(currentVertex, targetVertex, graph, (byte) 1);
    }

    return path;
}

ThetaFourVertex* RoutingAlgorithm::greedy(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, byte d){
    return u->getNeighbor(graph.getCone(*u, *t));
}

// string RoutingAlgorithm::bruteForce(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph){
//     if(graph.getVertex(xu,yu) == NULL || graph.getVertex(xt,yt) == NULL ) return "Invalid input!";

//     ThetaFourVertex *u = graph.getVertex(xu,yu);
//     ThetaFourVertex *t = graph.getVertex(xt,yt);
    
//     int d = (graph.getCone(*t, *u) == 0 || graph.getCone(*t, *u) == 2)  ? -1 : 1;
//     return ""

// }

// bool RoutingAlgorithm::clean(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, byte d){
//     int u_X = u->getX().value();
//     int u_Y = u->getY().value();

//     int t_X = u->getX().value();
//     int t_Y = u->getY().value();
// }