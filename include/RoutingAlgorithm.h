#ifndef ROUTING_ALGORITHM_H
#define ROUTING_ALGORITHM_H

#include "DirectedThetaFourGraph.h"

class RoutingAlgorithm{
    public: 
        //Algorithm
        string bruteForce(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph);
        string greedyRoutingOnly(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph);
        
        //
        bool clean(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, byte d);
        ThetaFourVertex* greedy(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, byte d);

};

#endif