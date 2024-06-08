#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

class Point{
    public: 
        Point(); 
        Point(int x, int y); 
        Point(const Point& point); 

        string print();
        int getX(); 
        int getY(); 
        void setY(int y);
        void setX(int x);

        double distanceTo(const Point& point);

    private: 
        int x; 
        int y;

};

#endif