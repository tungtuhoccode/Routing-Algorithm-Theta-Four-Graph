#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "PointTest.h"

using namespace std;

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);

    PointTest pointTester = PointTest();

    pointTester.TestAll();
    return RUN_ALL_TESTS();
}

