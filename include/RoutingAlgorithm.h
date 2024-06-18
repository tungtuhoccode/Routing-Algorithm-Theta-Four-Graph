#ifndef ROUTING_ALGORITHM_H
#define ROUTING_ALGORITHM_H

#include "DirectedThetaFourGraph.h"

class RoutingAlgorithm{
    public: 
        //Algorithm
        string greedyRoutingOnly(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph);
        string GreedySweepRouting(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph);
        
        int getClosestDiagonal(ThetaFourVertex* start, ThetaFourVertex* target, DirectedThetaFourGraph& graph);

        bool isClean(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, int d);
        ThetaFourVertex* greedy(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, int d);
        ThetaFourVertex* sweep(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, int d);

};

#endif