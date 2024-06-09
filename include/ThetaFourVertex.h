#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>

#include "Point.h"


using namespace std;
typedef pair<Point, double> NeightborDistancePair;
// Suggestion change: pair<ThetaFourVertex*, double> NeightborDistancePair;

class ThetaFourVertex{
    public: 
        ThetaFourVertex(); 
        ThetaFourVertex(int x, int y); //suggestion change to class: Change the constructors to make sure that it uses pointer
        ThetaFourVertex(Point point); 
        ThetaFourVertex(const ThetaFourVertex& vertex); 

        Point  getPoint() const;   
        //suggestion change to class: int getX()
        //suggestion change to class: int getY()
        //suggestion change to class: NeightborDistancePair
        
        double distanceTo(const ThetaFourVertex& vertex) const;
        NeightborDistancePair  getNeighbor(int coneI) const;
        void   setNeighbor(int coneI, Point point);
    
    private: 
        Point point;
        array<NeightborDistancePair, 4> neighbors; 
};

#endif