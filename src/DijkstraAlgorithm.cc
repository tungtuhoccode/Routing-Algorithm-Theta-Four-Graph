#include "../include/DirectedThetaFourGraph.h"
#include "../include/ThetaFourVertex.h"
#include "../include/DijkstraAlgorithm.h"

#include <map>
#include <queue> 

using namespace std;

typedef tuple<ThetaFourVertex, ThetaFourVertex, double> Edge; //VertexSource, VertexTarget, Weight

class myGreaterComparator 
{ 
public: 
    int operator() (const Edge& e1, const Edge& e2) 
    { 
        double w1 = get<2>(e1);
        double w2 = get<2>(e2);
        return w1 > w2; 
    } 
}; 

double DijkstraAlgorithm::shortestPath(int xs, int ys, int xt, int yt, DirectedThetaFourGraph& graph, int *numberOfEdges){
    if(graph.getVertex(xs,ys) == NULL || graph.getVertex(xt,yt) == NULL ) return -1;

    vector<ThetaFourVertex> vertices = graph.getAllVertices();

    //using priority queue
    priority_queue<Edge, vector<Edge>, myGreaterComparator > minHeap; // min heap of vertex id

    //map vertex to bool 
    unordered_map<int, bool> visited; // <Vertex.getID(), visited>
    unordered_map<int, double> minPathWeightToVertex; // <Vertex.getID(), weightToVertex>
    unordered_map<int, ThetaFourVertex> bestPreviousVertex;


    // Marks all vertices as not visited
    // Mark all vertices costs as inifnity
    for (int i = 0; i < vertices.size(); i++){
        int currentVertexID = vertices[i].getId();
        visited.insert({currentVertexID, false});
        minPathWeightToVertex.insert({currentVertexID, numeric_limits<double>::infinity()});
    }

    ThetaFourVertex start = *(graph.getVertex(xs, ys));

    minPathWeightToVertex[start.getId()] = 0;
    visited[start.getId()] = true;

    for (int i = 0; i < 4 ; i++){
        ThetaFourVertex* currentNeighbor = start.getNeighbor(i);
        if (currentNeighbor == NULL) continue;

        double weight = start.distanceTo(*currentNeighbor);
        minHeap.push(make_tuple(start, *currentNeighbor, weight));
    }

    //Start the algorithm 
    while (!minHeap.empty()){
        Edge currentBestEdge = minHeap.top();
        minHeap.pop();

        // cout << "current: " << get<1>(currentBestEdge).print() << endl;

        ThetaFourVertex previousVertexToCurrentVertex = get<0>(currentBestEdge);
        ThetaFourVertex currentVertex = get<1>(currentBestEdge);
        // cout << "" << get<1>(currentBestEdge).print() << endl;

        if (visited[currentVertex.getId()] == true) continue;

        // cout << "current Vertex: " << currentVertex.print() << endl;
        visited[currentVertex.getId()] = true;
        minPathWeightToVertex[currentVertex.getId()] = minPathWeightToVertex[previousVertexToCurrentVertex.getId()] + previousVertexToCurrentVertex.distanceTo(currentVertex);
        bestPreviousVertex[currentVertex.getId()] = previousVertexToCurrentVertex;

        //add new edges to the queue
        for (int i = 0; i < 4 ; i++){
            ThetaFourVertex* currentNeighbor = currentVertex.getNeighbor(i);

            if (currentNeighbor == NULL) continue;
            if (visited[currentNeighbor->getId()] == true) continue;

            //add this edge to the queue
            double weightToCurrentNeighbor = minPathWeightToVertex[currentVertex.getId()] + currentVertex.distanceTo(*currentNeighbor);
            minHeap.push(make_tuple(currentVertex, *currentNeighbor, weightToCurrentNeighbor));
        }

        // break the queue
    }

    //Added the target
    ThetaFourVertex previousVertex = bestPreviousVertex[graph.getVertex(xt, yt)->getId()];
    string returnStr = graph.getVertex(xt, yt)->print();
    int countEdges = 1;

    //Get the path by going backward through the list of vertices to the target
    while (previousVertex.getIntX() != xs && previousVertex.getIntY() != ys){
        returnStr = previousVertex.print() + " " + returnStr;
        previousVertex = bestPreviousVertex[previousVertex.getId()];
        countEdges++;
    }

    //Added the source 
    // returnStr = previousVertex.print() + " " + returnStr;
    countEdges++;
    // cout << "Number of edges using Dijkstra: " << countEdges << endl;


    // cout << "Shortest Path Length to current Vertex: " << returnStr << endl;
    *numberOfEdges = countEdges;
    return minPathWeightToVertex[graph.getVertex(xt, yt)->getId()];
}