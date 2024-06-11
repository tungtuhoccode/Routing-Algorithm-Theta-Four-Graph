objects = build/point.o build/thetaFourVertex.o build/directedThetaFourGraph.o
testerObjects = ./build/tester.o build/pointTest.o build/thetaFourVertexTest.o build/directedThetaFourGraphTest.o

compiler = g++ -std=c++15

TestDir = ./test
SourceDir = ./src
BuildDir = ./build
IncludeDir = ./include

compiler = c++ --std=gnu++17

all: test
 
main: ${objects}
	  ${compiler} -o ./bin/main $(objects) 

test: ${objects} ${testerObjects} 
	${compiler} -o ./bin/test ${objects} ${testerObjects} -lgtest -lgtest_main

runMain: 
	./bin/main

runTest: 
	./bin/test;

# Source Objects
build/point.o: ${SourceDir}/Point.cc ${IncludeDir}/point.h
	${compiler} -c ${SourceDir}/Point.cc -o build/point.o

build/thetaFourVertex.o: ${SourceDir}/ThetaFourVertex.cc ${IncludeDir}/thetaFourVertex.h
	${compiler} -c ${SourceDir}/ThetaFourVertex.cc -o build/thetaFourVertex.o

build/directedThetaFourGraph.o: ${SourceDir}/DirectedThetaFourGraph.cc ${IncludeDir}/DirectedThetaFourGraph.h
	${compiler} -c ${SourceDir}/DirectedThetaFourGraph.cc -o build/directedThetaFourGraph.o

build/main.o: ${SourceDir}/main.cc
	${compiler} -c ${SourceDir}/main.cc -o build/Main.o

# Tests
build/tester.o: ${TestDir}/Tester.cc
	${compiler} -c ${TestDir}/Tester.cc -o build/tester.o

build/pointTest.o: ${TestDir}/PointTest.cc
	${compiler} -c ${TestDir}/PointTest.cc -o build/pointTest.o

build/thetaFourVertexTest.o: ${TestDir}/ThetaFourVertexTest.cc
	${compiler} -c ${TestDir}/ThetaFourVertexTest.cc -o build/thetaFourVertexTest.o

build/directedThetaFourGraphTest.o: ${TestDir}/DirectedThetaFourGraphTest.cc ${IncludeDir}/DirectedThetaFourGraph.h
	${compiler} -c ${TestDir}/DirectedThetaFourGraphTest.cc -o build/directedThetaFourGraphTest.o

clean:
	cd bin; rm -f main *.o; cd ../build; rm -f *.o; cd ../bin; rm -f test;