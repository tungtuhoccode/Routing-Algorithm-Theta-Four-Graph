#include "../include/ThetaFourVertex.h"

int ThetaFourVertex::currentID = 0;


ThetaFourVertex::ThetaFourVertex(){
    id = currentID;
    currentID++;
    for(int i = 0; i < MAX_NEIGHBORS; i++){
        neighbors[i] = NULL;
    }
}

ThetaFourVertex::ThetaFourVertex(int x, int y){
    this->x = x;
    this->y = y;

    id = currentID;
    currentID++;

    for(int i = 0; i < MAX_NEIGHBORS; i++){
        neighbors[i] = NULL;
    }
}

ThetaFourVertex::ThetaFourVertex(const ThetaFourVertex& vertex){

    this->x = vertex.x;
    this->y = vertex.y;

    id = vertex.id;

    for(int i = 0; i < MAX_NEIGHBORS; i++){
        this->neighbors[i] = vertex.neighbors[i];
        if(vertex.neighbors[i] != NULL){
            distanceToNeighbor[i] = this->distanceTo(*(vertex.neighbors[i]));
        }
    }
}

double ThetaFourVertex::getDistanceToNeighbor(int coneI){
    return distanceToNeighbor[coneI];
}

void ThetaFourVertex::resetID(){
    currentID = 0;
}

int ThetaFourVertex::getId(){
    return this->id;
}

optional<int> ThetaFourVertex::getX(){
    return this->x;
}

optional<int> ThetaFourVertex::getY(){
    return this->y;
}

int ThetaFourVertex::getIntX(){
    return this->x.value();
}

int ThetaFourVertex::getIntY(){
    return this->y.value();
}


bool ThetaFourVertex::equals(int x, int y ){
    if (!(this->x.has_value()) || !(this->y.has_value())) throw std::logic_error("vertex is not set");
    return this->x == x && this->y == y;
}

ThetaFourVertex* ThetaFourVertex::getNeighbor(int coneI){
    if(coneI < 0 || coneI >= MAX_NEIGHBORS){
        throw std::invalid_argument( "Arguments must be in range 0 to 3" );
        return NULL; 
    }

    return neighbors[coneI];
}

double ThetaFourVertex::distanceTo(ThetaFourVertex& vertex){
    return sqrt(pow(vertex.x.value() - this->x.value(), 2) + pow( vertex.y.value() - this->y.value(), 2));
}
bool ThetaFourVertex::setNeighbor(int coneI, ThetaFourVertex* vertex){
    if(coneI < 0 || coneI >= MAX_NEIGHBORS){
        throw std::invalid_argument( "Arguments must be in range 0 to 3" );
        return false; 
    }

    this->neighbors[coneI] = vertex;
    return true;
}

string ThetaFourVertex::print(){
    if (!(this->x.has_value()) || !(this->y.has_value())) throw std::logic_error("vertex is not set");
    return  "{" + to_string(this->x.value()) + "," + to_string(this->y.value()) + "},";
}