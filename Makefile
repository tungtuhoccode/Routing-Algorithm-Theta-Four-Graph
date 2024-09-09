# objects = build/point.o build/thetaFourVertex.o build/directedThetaFourGraph.o build/routingAlgorithm.o
# testerObjects = ./build/tester.o build/pointTest.o build/thetaFourVertexTest.o build/directedThetaFourGraphTest.o build/algorithmTest.o

# compiler = g++ -std=c++15

# TestDir = ./test
# SourceDir = ./src
# BuildDir = ./build
# IncludeDir = ./include

# compiler = c++ --std=gnu++17

# all: test
 
# main: ${objects}
# 	  ${compiler} -o ./bin/main $(objects) 

# test: ${objects} ${testerObjects} 
# 	${compiler} -o ./bin/test ${objects} ${testerObjects} -lgtest -lgtest_main

# runMain: 
# 	./bin/main

# runTest: 
# 	./bin/test;

# # Source Objects
# build/point.o: ${SourceDir}/Point.cc ${IncludeDir}/point.h
# 	${compiler} -c ${SourceDir}/Point.cc -o build/point.o

# build/thetaFourVertex.o: ${SourceDir}/ThetaFourVertex.cc ${IncludeDir}/thetaFourVertex.h
# 	${compiler} -c ${SourceDir}/ThetaFourVertex.cc -o build/thetaFourVertex.o

# build/directedThetaFourGraph.o: ${SourceDir}/DirectedThetaFourGraph.cc ${IncludeDir}/DirectedThetaFourGraph.h
# 	${compiler} -c ${SourceDir}/DirectedThetaFourGraph.cc -o build/directedThetaFourGraph.o

# build/routingAlgorithm.o: ${SourceDir}/RoutingAlgorithm.cc ${IncludeDir}/RoutingAlgorithm.h
# 	${compiler} -c ${SourceDir}/RoutingAlgorithm.cc -o build/routingAlgorithm.o

# build/main.o: ${SourceDir}/main.cc
# 	${compiler} -c ${SourceDir}/main.cc -o build/Main.o

# # Tests
# build/tester.o: ${TestDir}/Tester.cc
# 	${compiler} -c ${TestDir}/Tester.cc -o build/tester.o

# build/pointTest.o: ${TestDir}/PointTest.cc
# 	${compiler} -c ${TestDir}/PointTest.cc -o build/pointTest.o

# build/thetaFourVertexTest.o: ${TestDir}/ThetaFourVertexTest.cc
# 	${compiler} -c ${TestDir}/ThetaFourVertexTest.cc -o build/thetaFourVertexTest.o

# build/directedThetaFourGraphTest.o: ${TestDir}/DirectedThetaFourGraphTest.cc ${IncludeDir}/DirectedThetaFourGraph.h
# 	${compiler} -c ${TestDir}/DirectedThetaFourGraphTest.cc -o build/directedThetaFourGraphTest.o

# build/algorithmTest.o: ${TestDir}/AlgorithmTest.cc ${IncludeDir}/DirectedThetaFourGraph.h
# 	${compiler} -c ${TestDir}/AlgorithmTest.cc -o build/algorithmTest.o

# clean:
# 	cd bin; rm -f main *.o; cd ../build; rm -f *.o; cd ../bin; rm -f test;

# Directories
TestDir = ./test
SourceDir = ./src
BuildDir = ./build
IncludeDir = ./include
BinDir = ./bin
BenchmarkDir = ./benchmark

# Compiler
compiler = g++ -std=gnu++17

# Source and Test Files
src_files := $(wildcard $(SourceDir)/*.cc)
test_files := $(wildcard $(TestDir)/*.cc)
objects := $(filter-out $(BuildDir)/main.o, $(patsubst $(SourceDir)/%.cc, $(BuildDir)/%.o, $(src_files)))
testerObjects := $(patsubst $(TestDir)/%.cc, $(BuildDir)/%.o, $(test_files))

benchmark_files := $(wildcard $(BenchmarkDir)/*.cc)
benchmarkObjects := $(patsubst $(BenchmarkDir)/%.cc, $(BuildDir)/%.o, $(benchmark_files))

# Targets
all: test main

main: $(objects) $(BuildDir)/main.o
	$(compiler) -pthread -o $(BinDir)/main -O2 $(objects) $(BuildDir)/main.o

test: $(objects) $(filter-out $(BuildDir)/main.o, $(testerObjects))
	$(compiler) -o $(BinDir)/test $(objects) $(filter-out $(BuildDir)/main.o, $(testerObjects)) -lgtest -lgtest_main

benchmark: $(objects) $(benchmarkObjects)
	$(compiler) -o $(BinDir)/benchmark $(objects) $(benchmarkObjects) -lbenchmark -lpthread

runBenchmark: benchmark
	./bin/benchmark

runMain: main
	./bin/main

runTest: test
	./bin/test

# Pattern rules
$(BuildDir)/%.o: $(SourceDir)/%.cc $(IncludeDir)/%.h
	$(compiler) -c $< -o $@

$(BuildDir)/main.o: $(SourceDir)/main.cc
	$(compiler) -c $< -o $@ 

$(BuildDir)/%.o: $(TestDir)/%.cc
	$(compiler) -c $< -o $@

$(BuildDir)/%.o: $(BenchmarkDir)/%.cc
	$(compiler) -c $< -o $@

clean:
	rm -f $(BuildDir)/*.o $(BinDir)/main $(BinDir)/test
