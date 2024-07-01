#ifndef ALGORITHM_ANALYZER_H
#define ALGORITHM_ANALYZER_H

#include "./ThetaFourVertex.h"

class AlgorithmAnalyzer{
    public: 
        vector<ThetaFourVertex> generateListOfVertices(int numbVertices);

        //helper method
        double getPathLength(vector<ThetaFourVertex>& path);

        time_t start;
        time_t finish;

};

#endif