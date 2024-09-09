#include "benchmark/benchmark.h"
#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"
#include "../include/ThetaFourVertex.h"
#include "../include/AlgorithmAnalyzer.h"
#include <chrono>
#include <string>

static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  // Initialize the list of vertices
    vector<ThetaFourVertex> vertices;

    // Array of vertices coordinates with both negative and positive values
    int verticesXY[100][2] = {
      {211196,-343923},
{260435,311948},
{456264,-69519},
{350782,-112090},
{284734,41803},
{26682,282074},
{-275294,-469842},
{-94186,-247029},
{62986,-90762},
{250906,-32567},
{-371652,-405047},
{350565,-246084},
{-455161,-284612},
{-314978,388920},
{-368364,-155905},
{406273,-39610},
{140362,-97100},
{261324,-143860},
{311305,280803},
{-440288,455841},
{248592,-212219},
{344755,481652},
{414868,-181416},
{-239895,284827},
{389621,276020},
{149953,443860},
{-248305,-198262},
{-203348,423952},
{439661,190341},
{216029,244464},
{295604,331039},
{-33190,364496},
{179219,-51541},
{454119,-480757},
{355411,422},
{-208521,-32646},
{289883,499587},
{-189421,-366930},
{223818,-312369},
{472077,-126923},
{361610,82272},
{318935,336478},
{-351218,353578},
{449794,-7404},
{174848,204225},
{105097,231855},
{357448,128177},
{24153,175956},
{386280,-72317},
{309746,-295212},
{-35204,-341646},
{-382028,34759},
{332468,-259888},
{265192,458021},
{86899,-346548},
{-18097,-318226},
{99753,-238451},
{-197630,91534},
{303081,222300},
{448281,82585},
{-489612,-256721},
{-194483,-418588},
{-334102,-169921},
{-166314,226267},
{268159,402736},
{-314519,234804},
{321888,-135258},
{222322,28385},
{139532,472059},
{-335956,-166967},
{148074,-17700},
{102357,11809},
{277811,-252620},
{-467254,-246144},
{363126,27607},
{-491814,452440},
{265266,106313},
{-290865,-310216},
{-10974,95998},
{81670,339871},
{319953,-56465},
{-252863,66055},
{266447,-72333},
{55433,425159},
{486595,-226352},
{420755,452116},
{-136455,-18251},
{28673,-130529},
{-179623,-449107},
{-375964,-95421},
{296240,2250},
{378384,-86004},
{254039,-227355},
{-179126,-404739},
{-116555,351052},
{197393,-301038},
{-224833,297650},
{-228293,181094},
{-266325,-99059},
{155313,-14026}
    };

    // Create ThetaFourVertex objects for each coordinate pair and add to vertices vector
    for (int i = 0; i < 100; ++i) {
        vertices.push_back(ThetaFourVertex(verticesXY[i][0], verticesXY[i][1]));
    }

    // Construct graph using the list of vertices
    DirectedThetaFourGraph graph = DirectedThetaFourGraph(vertices);

    RoutingAlgorithm algo;
    AlgorithmAnalyzer test;


    for (auto _ : state) {
      for (int i = 0; i < vertices.size() - 1; i++){
        for (int j = 0; j < vertices.size() - 1; j++){
          if (j == i) continue;
          algo.greedyRoutingOnlyReturnPath(verticesXY[i][0],verticesXY[i][1], verticesXY[j][0],verticesXY[j][1], graph);
        }
      }
     
    }
}


// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);

// Run the benchmark
BENCHMARK_MAIN();