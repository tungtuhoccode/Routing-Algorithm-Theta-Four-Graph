// Theta-four graph is a type of graph, that each vertices have up to four outgoing vertices

//constructor
// In order to construct the theta four graph, for each point, we have to do the following: 
// 1. Clasify the list of vertices for each cone of vertex u
// 2. Compute the value of each vertex for each cone 
// 3. Select the 1 vertex that has the max/min value for each cone to be the neightbor of u 

#ifndef DIRECTED_THETA_FOUR_GRAPH_H
#define DIRECTED_THETA_FOUR_GRAPH_H
#include <iostream>
#include <algorithm>

using namespace std; 

#include "ThetaFourVertex.h"

class DirectedThetaFourGraph{
    public:
        DirectedThetaFourGraph(vector<ThetaFourVertex> vertices); 

        bool setNeighborFor(ThetaFourVertex* vertex); //use this to set all four neightbors of a cone
        ThetaFourVertex* getVertex(int x, int y);

    private: 
        vector<ThetaFourVertex> vertices;
};

#endif