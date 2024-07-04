#include <iostream>
#include <string>
#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"
#include "../include/AlgorithmAnalyzer.h"
#include <set>
#include <vector>
#include <ctime>
using namespace std;


int main(){ 
    time_t start;
    time_t finish;
    AlgorithmAnalyzer analyzer;

    vector<ThetaFourVertex> vertices = analyzer.generateListOfVertices(2000);

    // Construct the graph using the list of vertices
    DirectedThetaFourGraph graph(vertices);
    time(&start);
    cout << "Time taken for constructing theta four graph = " << difftime(finish, start) << " seconds" << endl;

    RoutingAlgorithm algorithm;

    double spanningFactorGreedyOnly = 0;
    double spanningFactorGreedySweep = 0;

    double numberOfEdgesGreedyOnly = 0;
    double numberOfEdgesGreedySweep = 0;

    int numberOfPathTested = 0;

    for (int i = 0; i < vertices.size() - 1; i++){
        for (int j = 0; j < vertices.size() - 1; j++){
            numberOfPathTested++;
            cout << "***Test " << numberOfPathTested << " ***" << endl;
            if (j == i) continue;
            //get coordinates
            int x1 = vertices[i].getX().value();
            int y1 = vertices[i].getY().value();
            int x2 = vertices[j].getX().value();
            int y2 = vertices[j].getY().value();

            //calculate absolute distance
            double euclideanDistance = vertices[i].distanceTo(vertices[j]);

            vector<ThetaFourVertex> greedyOnlyPath = algorithm.greedyRoutingOnlyReturnPath(x1, y1, x2, y2, graph);
            vector<ThetaFourVertex> greedySweepPath = algorithm.GreedySweepRoutingReturnPath(x1, y1, x2, y2, graph);


            double greedyOnlyPathLength = analyzer.getPathLength(greedyOnlyPath);
            double greedySweepPathLength = analyzer.getPathLength(greedySweepPath);

            //Analysis for this path

            cout << "GreedyOnlyPath to Euclidean Path ratio: " << greedyOnlyPathLength/euclideanDistance << endl;
            cout << "GreedySweepPath to Euclidean Path ratio: " << greedySweepPathLength/euclideanDistance << endl;
            
            cout << "\nNumber of edges GreedyOnlyPath: " << greedyOnlyPath.size() << endl;
            cout << "Number of edges greedySweepPath: " << greedySweepPath.size() << endl;
            cout << endl;

            //Whole Graph Analysis
            spanningFactorGreedyOnly += (greedyOnlyPathLength/euclideanDistance);
            spanningFactorGreedySweep += (greedySweepPathLength/euclideanDistance);

            numberOfEdgesGreedyOnly += greedyOnlyPath.size();
            numberOfEdgesGreedySweep += greedySweepPath.size();
        }

    }

    //Result
    cout << "\n\n\n**** Analysis Result ****\n" << endl;

    cout << "Constant factor of GreedyOnly path: " << (spanningFactorGreedyOnly/ numberOfPathTested) << endl;
    cout << "Constant factor of GreedySweep path: " << (spanningFactorGreedySweep/ numberOfPathTested) << endl;

    cout << "\nNumber of average edges GreedyOnly path: " << numberOfEdgesGreedyOnly/numberOfPathTested <<endl;
    cout << "Number of average edges GreedySweep path: " << numberOfEdgesGreedySweep/numberOfPathTested <<endl;
   
    cout << "\n**** End ****\n" << endl;
    time(&finish);

    cout << "Time taken for running the algorithm = " << difftime(finish, start) << " seconds" << endl;

    return 0;
}