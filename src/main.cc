#include <iostream>
#include <string>
#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"
#include <set>
#include <vector>
#include <ctime>
using namespace std;


int main() {
    time_t start, finish;
    // Seed the random number generator
    std::srand(std::time(0));

    // Vector to hold 1000 vertices
    std::vector<ThetaFourVertex> vertices;

    // Define the range for coordinates
    const int RANGE_MIN = -1000;
    const int RANGE_MAX = 1000;

    // Sets to keep track of used x and y coordinates
    std::set<int> usedX;
    std::set<int> usedY;

    time(&start);

    // Generate 1000 unique vertices
    while (vertices.size() < 1000) {
        int x = RANGE_MIN + std::rand() % (RANGE_MAX - RANGE_MIN + 1);
        int y = RANGE_MIN + std::rand() % (RANGE_MAX - RANGE_MIN + 1);

        // Ensure x and y are unique
        if (usedX.find(x) == usedX.end() && usedY.find(y) == usedY.end()) { 
            vertices.push_back(ThetaFourVertex(x, y));
            cout << vertices[vertices.size()-1].print() << endl;
            usedX.insert(x);
            usedY.insert(y);
        }
    }
    time(&finish);
    cout << "Time taken for generating random list of vertices = " << difftime(finish, start) << " seconds" << endl;

    time(&start);
    // Construct the graph using the list of vertices
    DirectedThetaFourGraph graph(vertices);
    time(&finish);
    cout << "Time taken for constructing theta four graph = " << difftime(finish, start) << " seconds" << endl;

    RoutingAlgorithm algorithm;

    
    time(&start);

    int tests[10] = {100,504,345,254,2567,222,1568, 902, 201, 1085};
    for (int i =0;i<9;i++){
        if (i==1){
        cout << algorithm.greedyRoutingOnly(vertices[i].getX().value(), vertices[i].getY().value(), vertices[i+1].getX().value(), vertices[i+1].getY().value(), graph ) << endl;
        cout << algorithm.GreedySweepRouting(vertices[i].getX().value(), vertices[i].getY().value(), vertices[i+1].getX().value(), vertices[i+1].getY().value(), graph ) << endl;
        }
    }
   
    time(&finish);
    cout << "Time taken for running the algorithm = " << difftime(finish, start) << " seconds" << endl;

    return 0;
}