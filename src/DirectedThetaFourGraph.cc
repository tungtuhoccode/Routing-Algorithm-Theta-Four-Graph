#include "../include/DirectedThetaFourGraph.h"
#include <ctime>

DirectedThetaFourGraph::DirectedThetaFourGraph(vector<ThetaFourVertex> verticesInput){
    //add vertices
    for (int i=0; i < verticesInput.size(); ++i){
        vertices.push_back(verticesInput[i]);
    }

    time_t start, finish;
    time(&start);
    //add edges
    for (int i=0; i<vertices.size(); ++i){
        setNeighborsFor(&vertices[i]);
    }
    time(&finish);
    cout << "Time taken for add edges theta four graph = " << difftime(finish, start) << " seconds" << endl;
}

vector<ThetaFourVertex> DirectedThetaFourGraph::getAllVertices(){
    return vertices;
}

ThetaFourVertex* DirectedThetaFourGraph::getVertex(int x, int y){
    for (int i=0; i < vertices.size(); ++i){
        ThetaFourVertex currentVertex = vertices[i];
        if(vertices[i].equals(x,y)) return &vertices[i];
    }
    return NULL;
}

bool DirectedThetaFourGraph::setNeighborsFor(ThetaFourVertex* vertex){
    //loop through each vertex
    for (int i = 0; i < vertices.size(); ++i){
        ThetaFourVertex& currentVertex = vertices[i];
        //vertex == currentVertex
        if(vertices[i].equals(vertex->getX().value(), vertex->getY().value())) continue;

        //for other vertices
        int currentVertexCone = getCone(*vertex, vertices[i]);

        if(vertex->getNeighbor(currentVertexCone) == NULL) vertex->setNeighbor(currentVertexCone, &currentVertex);
        else{
            if(isCloser(currentVertexCone, *vertex, currentVertex)){
                vertex->setNeighbor(currentVertexCone, &currentVertex);
            }
        }
    }
    return true;
}

bool DirectedThetaFourGraph::isCloser(int coneI, ThetaFourVertex& absoluteVertex, ThetaFourVertex& relativeVertex){
    int absX = absoluteVertex.getNeighbor(coneI)->getX().value();
    int absY = absoluteVertex.getNeighbor(coneI)->getY().value();

    int relX = relativeVertex.getX().value();
    int relY = relativeVertex.getY().value();

    switch (coneI)
    {
    case 0:
        if( (-relX + relY) > (-absX + absY) ) return true;
        break;
    case 1:
        if( (relX + relY) < (absX + absY) ) return true;
        break;
    case 2:
        if( (-relX + relY) < (-absX + absY) ) return true;
        break;
    case 3:
        if( (relX + relY) > (absX + absY) ) return true;
        break;
    }

    if (absoluteVertex.distanceTo(relativeVertex) < absoluteVertex.distanceTo(*absoluteVertex.getNeighbor(coneI))){
            return true;
    }

    return false;
}



int DirectedThetaFourGraph::getCone(ThetaFourVertex& absoluteVertex, ThetaFourVertex& relativeVertex) const{
    if(absoluteVertex.getX() == relativeVertex.getX() || absoluteVertex.getY() == relativeVertex.getY()){
        throw std::invalid_argument("Two vertices cannot have the same x or y coordinate");
    }

    if(absoluteVertex.getX() < relativeVertex.getX()){
        if(absoluteVertex.getY() > relativeVertex.getY()) return 0;
        else return 1;
    }
    else{
        if(absoluteVertex.getY() < relativeVertex.getY()) return 2;
        else return 3;
    }
}
