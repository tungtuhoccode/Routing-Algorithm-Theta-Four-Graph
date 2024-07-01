#include <iostream>
#include <string>
#include "../include/AlgorithmAnalyzer.h"

#include <set>
#include <iomanip>
using namespace std;

vector<ThetaFourVertex> AlgorithmAnalyzer::generateListOfVertices(int numbVertices){
    //timer
    time(&start);   

    //bound check
    if (numbVertices > 100000) throw range_error("Number of vertices exceeded 100,000 (Allowed <= 100,000)");

    //return list of vertices
    vector<ThetaFourVertex> vertices;

    // Define the range for coordinates
    const int RANGE_MIN = -500000;
    const int RANGE_MAX = 500000;

    // Sets to keep track of used x and y coordinates
    set<int> usedX;
    set<int> usedY;

    //seed for random number generator
    srand(time(0));

    //generate random vertices
    while (vertices.size() < numbVertices) {
        int x = RANGE_MIN + rand() % (RANGE_MAX - RANGE_MIN + 1);
        if (usedX.find(x) != usedX.end()) continue;

        int y = RANGE_MIN + rand() % (RANGE_MAX - RANGE_MIN + 1);
        if (usedY.find(y) != usedY.end()) continue;

        //add new unique vertex to the list
        vertices.push_back(ThetaFourVertex(x, y));

        //log the generate vertices
        cout << vertices[vertices.size()-1].print() << endl;

        //add x and y to the used list
        usedX.insert(x);
        usedY.insert(y);
    }

    time(&finish);

    double time_taken = double(finish - start);

    cout << "Time taken for generating random list of vertices = " << time_taken << setprecision(5) <<  " seconds" << endl;

    return vertices;
}
