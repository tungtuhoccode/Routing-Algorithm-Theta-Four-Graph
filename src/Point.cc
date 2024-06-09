#include "../include/Point.h"

Point::Point(int x, int y): x(x), y(y) {

}

Point::Point(const Point& point): x(point.x), y(point.y) {

}

int Point::getX() const{
    return this->x;
}

int Point::getY() const{
    return this->y;
}

void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

double Point::distanceTo(const Point& point) const{
    return sqrt(pow(point.x - this->x, 2) + pow( point.y - this->y, 2));
}

string Point::print(){
    return  "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
}



 
