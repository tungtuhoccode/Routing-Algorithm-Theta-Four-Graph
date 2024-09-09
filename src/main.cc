#include <iostream>
#include <string>
#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"
#include "../include/AlgorithmAnalyzer.h"
#include "../include/DijkstraAlgorithm.h"
#include <set>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mtx;


int TestMain(int numbVer){ 
    time_t start;
    time_t finish;
    AlgorithmAnalyzer analyzer;

    vector<ThetaFourVertex> vertices = analyzer.generateListOfVertices(numbVer);

    // Construct the graph using the list of vertices
    DirectedThetaFourGraph graph(vertices);
    time(&start);
    cout << "Time taken for constructing theta four graph = " << difftime(finish, start) << " seconds" << endl;

    RoutingAlgorithm algorithm;
    DijkstraAlgorithm dijkstra;

    double spanningFactorGreedyOnly = 0;
    double spanningFactorGreedySweep = 0;
    double spanningDijkstra = 0;

    double numberOfEdgesGreedyOnly = 0;
    double numberOfEdgesGreedySweep = 0;

    int numberOfPathTested = 0;

    for (int i = 0; i < vertices.size(); i++){
        for (int j = i + 1; j < vertices.size(); j++){

            // cout << "***Test " << numberOfPathTested << " ***" << endl;
            if (j == i) continue;
            numberOfPathTested++;
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
            double dijkstraPathLength = dijkstra.shortestPath(x1, y1, x2, y2, graph);
            
            //Analysis for this path
            // cout << "Dijkstra to Euclidean Path ratio: " << dijkstraPathLength/euclideanDistance << endl;
            // cout << "GreedyOnlyPath to Euclidean Path ratio: " << greedyOnlyPathLength/euclideanDistance << endl;
            // cout << "GreedySweepPath to Euclidean Path ratio: " << greedySweepPathLength/euclideanDistance << endl;
            
            // cout << "\nNumber of edges GreedyOnlyPath: " << greedyOnlyPath.size()-1 << endl;
            // cout << "Number of edges greedySweepPath: " << greedySweepPath.size()-1 << endl;
            // cout << endl;

            //Whole Graph Analysis
            spanningFactorGreedyOnly += (greedyOnlyPathLength/euclideanDistance);
            spanningFactorGreedySweep += (greedySweepPathLength/euclideanDistance);
            spanningDijkstra += dijkstraPathLength/euclideanDistance;

            numberOfEdgesGreedyOnly += greedyOnlyPath.size();
            numberOfEdgesGreedySweep += greedySweepPath.size();
        }

    }

    //Result
    cout << "\n\n\n**** Analysis Result 2 ****\n" << endl;

    cout << "spanningDijkstra: " << spanningDijkstra << endl; 
    cout << "spanningFactorGreedyOnly: " << spanningFactorGreedyOnly << endl;
    cout << "numberOfPathTested: " << numberOfPathTested << endl;

    cout << "Constant factor of Dijkstra path: " << (spanningDijkstra/ numberOfPathTested) << endl;
    cout << "Constant factor of GreedyOnly path: " << (spanningFactorGreedyOnly/ numberOfPathTested) << endl;   
    cout << "Constant factor of GreedySweep path: " << (spanningFactorGreedySweep/ numberOfPathTested) << endl;

    cout << "\nNumber of average edges GreedyOnly path: " << numberOfEdgesGreedyOnly/numberOfPathTested <<endl;
    cout << "Number of average edges GreedySweep path: " << numberOfEdgesGreedySweep/numberOfPathTested <<endl;
   
    cout << "\n**** End ****\n" << endl;
    time(&finish);

    cout << "Time taken for running the algorithm = " << difftime(finish, start) << " seconds" << endl;

    return 0;
}

void analyze_in_range(int startIndex, int endIndex, 
double *spanningFactorGreedyOnly, double *spanningFactorGreedySweep, double *spanningDijkstra, double *numberOfEdgesGreedyOnly, double *numberOfEdgesGreedySweep, int *numberOfPathTested,
vector<ThetaFourVertex>& vertices, DirectedThetaFourGraph& graph, AlgorithmAnalyzer& analyzer, RoutingAlgorithm& routingAlgo, DijkstraAlgorithm& dijkstra){
    double localSpanningFactorGreedyOnly = 0;
    double localSpanningFactorGreedySweep = 0;
    double localSpanningDijkstra = 0;

    double localNumberOfEdgesGreedyOnly = 0;
    double localNumberOfEdgesGreedySweep = 0;
        
    int localNumberOfPathTested = 0;

    for (int i = startIndex; i <= endIndex; i++){
        int x1 = vertices[i].getX().value();
        int y1 = vertices[i].getY().value();

        if(startIndex == 0 ){
            cout << "Progress: " << (int)(((double)(i-startIndex))/((double)(endIndex-startIndex))*100) << "%" << endl;
        }
        
        for (int j = i + 1; j < vertices.size(); j++){
            // cout << "***Test " << localNumberOfPathTested << " ***" << endl



            if (j == i) continue;
            ++localNumberOfPathTested;
            //get coordinates
            int x2 = vertices[j].getX().value();
            int y2 = vertices[j].getY().value();

            //calculate absolute distance
            double euclideanDistance = vertices[i].distanceTo(vertices[j]);

            vector<ThetaFourVertex> greedyOnlyPath = routingAlgo.greedyRoutingOnlyReturnPath(x1, y1, x2, y2, graph);
            vector<ThetaFourVertex> greedySweepPath = routingAlgo.GreedySweepRoutingReturnPath(x1, y1, x2, y2, graph);

            double greedyOnlyPathLength = analyzer.getPathLength(greedyOnlyPath);
            double greedySweepPathLength = analyzer.getPathLength(greedySweepPath);
            double dijkstraPathLength = dijkstra.shortestPath(x1, y1, x2, y2, graph);

            
            //Analysis for this path
            // cout << "Dijkstra to Euclidean Path ratio: " << dijkstraPathLength/euclideanDistance << endl;
            // cout << "GreedyOnlyPath to Euclidean Path ratio: " << greedyOnlyPathLength/euclideanDistance << endl;
            // cout << "GreedySweepPath to Euclidean Path ratio: " << greedySweepPathLength/euclideanDistance << endl;
            
            // cout << "\nNumber of edges GreedyOnlyPath: " << greedyOnlyPath.size()-1 << endl;
            // cout << "Number of edges greedySweepPath: " << greedySweepPath.size()-1 << endl;
            // cout << endl;

            // Whole Graph Analysis
            localSpanningFactorGreedyOnly += (greedyOnlyPathLength/euclideanDistance);
            localSpanningFactorGreedySweep += (greedySweepPathLength/euclideanDistance);
            localSpanningDijkstra += dijkstraPathLength/euclideanDistance;

            localNumberOfEdgesGreedyOnly += greedyOnlyPath.size();
            localNumberOfEdgesGreedySweep += greedySweepPath.size();
        }

    }

    //MUTEX LOCK 
    unique_lock<mutex> lock(mtx);
    *spanningFactorGreedyOnly  += localSpanningFactorGreedyOnly;
    *spanningFactorGreedySweep += localSpanningFactorGreedySweep;
    *spanningDijkstra += localSpanningDijkstra;
    *numberOfEdgesGreedyOnly += localNumberOfEdgesGreedyOnly;
    *numberOfEdgesGreedySweep += localNumberOfEdgesGreedySweep;
    *numberOfPathTested += localNumberOfPathTested;

    //MUTEX UNLOCK
    lock.unlock();
}

int main(){ 
    //initilization
    time_t start;
    time_t finish;
    AlgorithmAnalyzer analyzer;

    int numbVertices = 200;
    // estimateTrials = numbVertices * numbVertices;

    vector<ThetaFourVertex> vertices = analyzer.generateListOfVertices(numbVertices);

    // Construct the graph using the list of vertices
    time(&start);
    DirectedThetaFourGraph graph(vertices);
    time(&finish);
    cout << "Time taken for constructing theta four graph = " << difftime(finish, start) << " seconds" << endl;

    RoutingAlgorithm algorithm;
    DijkstraAlgorithm dijkstra;

    double spanningFactorGreedyOnly = 0;
    double spanningFactorGreedySweep = 0;
    double spanningDijkstra = 0;

    double numberOfEdgesGreedyOnly = 0;
    double numberOfEdgesGreedySweep = 0;

    int numberOfPathTested = 0;

    int lastTrial = 0;

    //multi threading analysis
    int num_threads = 10;
    int numbTrialsPerThread = (numbVertices % num_threads) == 0 ? (numbVertices/num_threads) : (numbVertices/num_threads + 1);
    vector<thread> threads;


    for (int i = 0; i < vertices.size() - numbTrialsPerThread; i += numbTrialsPerThread){
        // analyze_in_range(i, i += (numbTrialsPerThread - 1), )
        lastTrial = i + (numbTrialsPerThread - 1);

        threads.push_back(thread(analyze_in_range, i, lastTrial, &spanningFactorGreedyOnly, &spanningFactorGreedySweep, &spanningDijkstra, 
        &numberOfEdgesGreedyOnly, &numberOfEdgesGreedySweep, &numberOfPathTested, 
        ref(vertices), ref(graph), ref(analyzer), ref(algorithm), ref(dijkstra)));
    }

    threads.push_back(thread(analyze_in_range, lastTrial + 1, numbVertices - 1, &spanningFactorGreedyOnly, &spanningFactorGreedySweep, &spanningDijkstra, 
    &numberOfEdgesGreedyOnly, &numberOfEdgesGreedySweep, &numberOfPathTested, 
    ref(vertices), ref(graph), ref(analyzer), ref(algorithm), ref(dijkstra)));

    // Joining all threads
    for (auto &th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    time(&finish);
    cout << "Finished multithreading in " << difftime(finish, start) << " seconds" << endl;

    //Result
    cout << "\n\n\n**** Analysis Result ****\n" << endl;
    cout << "spanningDijkstra: " << spanningDijkstra << endl; 
    cout << "spanningFactorGreedyOnly: " << spanningFactorGreedyOnly << endl;
    cout << "numberOfPathTested: " << numberOfPathTested << endl;

    cout << "Constant factor of Dijkstra path: " << (spanningDijkstra/ numberOfPathTested) << endl;
    cout << "Constant factor of GreedyOnly path: " << (spanningFactorGreedyOnly/ numberOfPathTested) << endl;   
    cout << "Constant factor of GreedySweep path: " << (spanningFactorGreedySweep/ numberOfPathTested) << endl;

    cout << "\nNumber of average edges GreedyOnly path: " << numberOfEdgesGreedyOnly/numberOfPathTested <<endl;
    cout << "Number of average edges GreedySweep path: " << numberOfEdgesGreedySweep/numberOfPathTested <<endl;
   
    cout << "\n**** End ****\n" << endl;
    time(&finish);

    cout << "Time taken for running the algorithm = " << difftime(finish, start) << " seconds" << endl;

    TestMain(numbVertices);

    return 0;
}

//this function will analyze for the specified range (startIndex -> endIndex inclusive).
