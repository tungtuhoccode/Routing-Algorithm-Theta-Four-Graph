#include "../include/ThetaFourVertex.h"

ThetaFourVertex::ThetaFourVertex(){
    for(int i = 0; i < MAX_NEIGHBORS; i++){
        neighbors[i] = NULL;
    }
}

ThetaFourVertex::ThetaFourVertex(int x, int y){
    this->x = x;
    this->y = y;

    for(int i = 0; i < MAX_NEIGHBORS; i++){
        neighbors[i] = NULL;
    }
}

ThetaFourVertex::ThetaFourVertex(ThetaFourVertex& vertex){
    this->x = vertex.getX();
    this->y = vertex.getY();

    for(int i = 0; i < MAX_NEIGHBORS; i++){
        this->neighbors[i] = vertex.getNeighbor(i);
    }
}

optional<int> ThetaFourVertex::getX(){
    return this->x;
}

optional<int> ThetaFourVertex::getY(){
    return this->y;
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

bool ThetaFourVertex::setNeighbor(int coneI, ThetaFourVertex* vertex){
    if(coneI < 0 || coneI >= MAX_NEIGHBORS){
        throw std::invalid_argument( "Arguments must be in range 0 to 3" );
        return false; 
    }

    this->neighbors[coneI] = vertex;
    return true;
}