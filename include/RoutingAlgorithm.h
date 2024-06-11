#ifndef ROUTING_ALGORITHM_H
#define ROUTING_ALGORITHM_H

#include "DirectedThetaFourGraph.h"
#
class RoutingAlgorithm{
    public: 

        bool clean(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, byte d);
        string bruteForce(int x1, int y1, int x2, int y2, DirectedThetaFourGraph& graph, byte d);
};

#endif ROUTING_ALGORITHM_H