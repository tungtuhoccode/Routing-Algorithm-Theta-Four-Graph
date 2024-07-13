#ifndef DIJKSTRA_ALGORITHM_H
#define DIJKSTRA_ALGORITHM_H

#include "../include/DirectedThetaFourGraph.h"
#include "../include/ThetaFourVertex.h"

class DijkstraAlgorithm{
    
    public: 
        double shortestPath(int xs, int ys, int xt, int yt, DirectedThetaFourGraph& graph);

};

#endif