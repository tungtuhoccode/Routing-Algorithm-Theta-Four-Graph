#ifndef DIRECTED_THETA_FOUR_GRAPH_H
#define DIRECTED_THETA_FOUR_GRAPH_H
#include <iostream>
#include <algorithm>

using namespace std; 

#include "ThetaFourVertex.h"

class DirectedThetaFourGraph{
    public:
        DirectedThetaFourGraph(vector<ThetaFourVertex> verticesInput); 

        bool setNeighborsFor(ThetaFourVertex* vertex); //use this to set all four neightbors of a cone
        ThetaFourVertex* getVertex(int x, int y);
        int getCone(ThetaFourVertex& absoluteVertex, ThetaFourVertex& relativeVertex) const;
        bool isCloser(int coneI, ThetaFourVertex& absoluteVertex, ThetaFourVertex& relativeVertex);
        
    private: 
        vector<ThetaFourVertex> vertices;
};

#endif