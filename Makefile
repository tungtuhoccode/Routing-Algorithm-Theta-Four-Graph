objects = build/point.o
testerObjects = build/pointTest.o

compiler = g++ -std=c++15

TestDir = ./test
SourceDir = ./src
BuildDir = ./build
IncludeDir = ./include

compiler = c++ --std=gnu++17

all: test
 
main: ${objects}
	  ${compiler} -o ./bin/main $(objects) 

test: ${objects} ${testerObjects} ./build/tester.o
	${compiler} -o ./bin/test ./build/tester.o ${objects} ${testerObjects} -lgtest -lgtest_main

runMain: 
	./bin/main

runTest: 
	./bin/test;


build/point.o: ${SourceDir}/Point.cc ${IncludeDir}/point.h
	${compiler} -c ${SourceDir}/Point.cc -o build/point.o

build/main.o: ${SourceDir}/main.cc
	${compiler} -c ${SourceDir}/main.cc -o build/Main.o

build/tester.o: ${TestDir}/Tester.cc
	${compiler} -c ${TestDir}/Tester.cc -o build/tester.o

build/pointTest.o: ${TestDir}/PointTest.cc
	${compiler} -c ${TestDir}/PointTest.cc -o build/pointTest.o

clean:
	cd bin; rm -f main *.o; cd ../build; rm -f *.o; cd ../bin; rm -f test;