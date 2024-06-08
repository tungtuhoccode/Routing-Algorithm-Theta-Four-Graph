#include "../include/Point.h"

Point::Point(): x(0), y(0){

}

Point::Point(int x, int y): x(x), y(y) {

}

Point::Point(const Point& point): x(point.x), y(point.y) {

}

int Point::getX(){
    return this->x;
}

int Point::getY(){
    return this->y;
}

void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

double Point::distanceTo(const Point& point){
    return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
}

string Point::print(){
    return  "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
}



 
