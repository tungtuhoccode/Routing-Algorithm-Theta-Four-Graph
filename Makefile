objects = build/main.o
compiler = g++ -std=c++11

TestDir = ./test
SourceDir = ./src
BuildDir = ./build
IncludeDir = ./include

compiler = g++ -std=c++11

all: main

main: ${objects}
	  ${compiler} -o ./bin/main $(objects) 

run: 
	./bin/main

build/main.o: ${SourceDir}/main.cc
	${compiler} -c ${SourceDir}/main.cc -o build/main.o

clean:
	cd bin; rm -f main *.o; cd ../build; rm -f *.o