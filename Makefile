
SRC_DIR := src/algorithms
ALG_DIR := build/algorithms

CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(ALG_DIR)/%.o,$(CPP_FILES))

all: build build/algorithms build/main build/factory_method_pattern

build/main: src/main.cpp $(OBJ_FILES) build/data_generator.o
	g++ -std=c++17 -Wall -o $@ $^

build/data_generator.o: src/data_generator.h src/data_generator.cpp
	g++ -std=c++17 -Wall -o build/data_generator.o -c src/data_generator.cpp

$(ALG_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -std=c++17 -Wall -o $@ -c $<


build/factory_method_pattern: src/factory_method_pattern.cpp $(OBJ_FILES)
	g++ -std=c++17 -Wall -o $@ $^

build:
	mkdir -p build

build/algorithms: build
	mkdir -p build/algorithms


run: build/main
	./build/main


tea: build/tea

build/tea: build/tea.cpp
	g++-8 -fextended-identifiers -finput-charset=utf-8 -std=c++2a -Wall -o $@ $^

build/tea.cpp: src/bubble_tea_factory.cpp
	uni2ascii -aL src/bubble_tea_factory.cpp > $@