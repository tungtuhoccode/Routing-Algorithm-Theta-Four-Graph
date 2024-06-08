#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>

#include "Point.h"


using namespace std;
typedef tuple<Point, double> QuaternaryTuple;

class ThetaFourVertex{
    public: 
        ThetaFourVertex(); 
        ThetaFourVertex(int x, int y);
        ThetaFourVertex(Point point); 
        ThetaFourVertex(const ThetaFourVertex& vertex); 

        Point  getPoint() const;   
        tuple<Point, double>  getNeighbor(int coneI) const;
        void   setNeighbor(int coneI, Point point);
    
    private: 
        Point point;
        array<tuple<Point, double>, 4> neighbors; 
        // Point neighbors[4];
};

#endif