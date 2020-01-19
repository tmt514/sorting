all: build/main

build/main: src/main.cpp build/sort.o build/data_generator.o
	g++ -O1 -std=c++17 -Wall -o build/main src/main.cpp build/sort.o build/data_generator.o

build/data_generator.o: src/data_generator.h src/data_generator.cpp
	g++ -O1 -std=c++17 -Wall -o build/data_generator.o -c src/data_generator.cpp

build/sort.o: src/sort.h src/sort.cpp src/sorter_factory.h
	g++ -O1 -std=c++17 -Wall -o build/sort.o -c src/sort.cpp
	
run: build/main
	./build/main