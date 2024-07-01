#include <iostream>
#include <string>
#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"
#include "../include/AlgorithmAnalyzer.h"
#include <set>
#include <vector>
#include <ctime>
using namespace std;


int main() {
    time_t start;
    time_t finish;
    AlgorithmAnalyzer analyzer;

    vector<ThetaFourVertex> vertices = analyzer.generateListOfVertices(10000);

    // Construct the graph using the list of vertices
    DirectedThetaFourGraph graph(vertices);
    time(&finish);
    cout << "Time taken for constructing theta four graph = " << difftime(finish, start) << " seconds" << endl;

    RoutingAlgorithm algorithm;
    
    vector<ThetaFourVertex> greedyPath;
    vector<ThetaFourVertex> greedySweepPath;

    string strPath = "";

    double greedyPathLength = 0;
    double greedySweepPathLength = 0;

    time(&start);

    int countGreedyBetter = 0;
    int countGreedySweepBetter = 0;
    int samePerformance = 0;

    double greedyOnlyExtraDistance = 0;
    double greedySweepExtraDistance = 0;

    for (int i =0;i < vertices.size() - 1;i++){
        cout << "Test " << i << endl;
        double euclideanDistance = vertices[i].distanceTo(vertices[i+1]);
        
        greedyPath = algorithm.greedyRoutingOnlyReturnPath(vertices[i].getX().value(), vertices[i].getY().value(), vertices[i+1].getX().value(), vertices[i+1].getY().value(), graph );
        greedySweepPath = algorithm.GreedySweepRoutingReturnPath(vertices[i].getX().value(), vertices[i].getY().value(), vertices[i+1].getX().value(), vertices[i+1].getY().value(), graph );

        greedyPathLength = 0;
        greedySweepPathLength = 0;
        for (int i = 1; i < greedyPath.size(); i++){
            greedyPathLength += greedyPath[i].distanceTo(greedyPath[i-1]);
        }

        cout << "Greedy Only Path Length: " << greedyPathLength << endl;

        for (int i = 1; i < greedySweepPath.size(); i++){
            greedySweepPathLength += greedySweepPath[i].distanceTo(greedySweepPath[i-1]);
        }

        if(greedyPathLength < greedySweepPathLength){
            greedySweepExtraDistance += greedySweepPathLength - greedyPathLength;
            countGreedyBetter++;
        }
        else if (greedyPathLength == greedySweepPathLength){
            samePerformance += 1;
        }
        else{
            greedyOnlyExtraDistance +=  greedyPathLength -  greedySweepPathLength;
            countGreedySweepBetter++;
        }

        cout << "Greedy/Sweep Path Length: " << greedySweepPathLength << endl;
    }

    cout << "\n\n\n**** Analysis Result ****\n" << endl;
     
    cout << "Greedy/Sweep and GreedyOnly perform the same: " << samePerformance << "times." << endl;

    cout << "Greedy/Sweep outperform GreedyOnly: " << countGreedySweepBetter << "times." << endl;
    cout << "Greedy/Sweep is longer than GreedyOnly on average: " << greedySweepExtraDistance/countGreedyBetter << " length units." << endl;

    cout << "" << endl;

    cout << "GreedyOnly outperform Greedy/Sweep : " << countGreedyBetter << "times." << endl;
    cout << "GreedyOnly is longer than Greedy/Sweep on average: " << greedyOnlyExtraDistance/countGreedySweepBetter << " length units." << endl;
   
    cout << "\n**** End ****\n" << endl;
    time(&finish);

    cout << "Time taken for running the algorithm = " << difftime(finish, start) << " seconds" << endl;

    return 0;
}