#include "../include/DirectedThetaFourGraph.h"
#include "../include/ThetaFourVertex.h"
#include "../include/DijkstraAlgorithm.h"

#include <map>
#include <queue> 

using namespace std;

typedef pair<int, int> VertexCoordinate; // pair<int,int>(x, y)

typedef tuple<VertexCoordinate, VertexCoordinate, double> Edge; //VertexSource, VertexTarget, Weight

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

string DijkstraAlgorithm::shortestPath(int xs, int ys, int xt, int yt, DirectedThetaFourGraph& graph){
    vector<ThetaFourVertex> vertices = graph.getAllVertices();

    
    //array of all vertices
    int pathAndCostArr[vertices.size()];
    bool visited[vertices.size()];

    //using priority queue
    priority_queue<Edge, vector<Edge>, myGreaterComparator > minHeap; // min heap of vertex id

    for (int i = 0; i < vertices.size(); i++){
        ThetaFourVertex currentVertex = vertices[i];
        VertexCoordinate source = make_pair()
        for (int j = 0; j < 4; j++){
           
            minHeap.push(make_tuple(make_pair))
            //try to add elements to the minHeap
        }
    }

    try to print it all out

    return "";
}