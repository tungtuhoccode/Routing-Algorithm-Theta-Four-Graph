#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

class Point{
    public: 
        Point() = default; //by default, all point will be (0,0)
        Point(int x, int y); 
        Point(const Point& point); 

        string print();
        int getX() const; 
        int getY() const; 
        void setY(int y);
        void setX(int x);

        double distanceTo(const Point& point) const;

    private: 
        int x; 
        int y;

};

#endif