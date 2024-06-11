#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>
#include <string>


using namespace std;
#define MAX_NEIGHBORS 4

class ThetaFourVertex{
    public: 
        ThetaFourVertex(); 
        ThetaFourVertex(int x, int y); 
        ThetaFourVertex(const ThetaFourVertex& vertex); 

        optional<int> getX();
        optional<int> getY();
        bool equals(int x, int y);
        string print();
        double distanceTo(ThetaFourVertex& vertex);

        // double distanceTo(const ThetaFourVertex& vertex) const;
        ThetaFourVertex* getNeighbor(int coneI);
        bool   setNeighbor(int coneI, ThetaFourVertex* vertex);

    private: 
        optional<int> x; 
        optional<int> y; 
        ThetaFourVertex* neighbors[4];
};

#endif