#include "../include/ThetaFourVertex.h"

ThetaFourVertex::ThetaFourVertex(){

}

ThetaFourVertex::ThetaFourVertex(int x, int y){
    this->point = Point(x, y);
}

ThetaFourVertex::ThetaFourVertex(Point point){
    this->point = point;
}

ThetaFourVertex::ThetaFourVertex(const ThetaFourVertex& vertex){
    this->point = vertex.point;
    for(int i = 0; i < 4; i++){
        this->neighbors[i] = make_tuple(point, this->point.distanceTo(point));
    }
}

Point ThetaFourVertex::getPoint() const{
    return this->point;
}

tuple<Point, double> ThetaFourVertex::getNeighbor(int coneI) const{
    return this->neighbors[coneI];
}

void ThetaFourVertex::setNeighbor(int coneI, Point point){
    tuple<Point, double> neighbor = make_tuple(point, this->point.distanceTo(point));
    this->neighbors[coneI] = neighbor;
}