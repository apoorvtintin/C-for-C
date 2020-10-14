CC = clang++
INCLUDE_DIR = -I./../include/
CFLAGS  = -o0 -O -Wall -Werror -g -std=c++11 $(INCLUDE_DIR)
BIN_DIR = ../bin/
OBJ_DIR = ../obj/

CPPFILES = $(wildcard *.cpp)
HFILES = $(wildcard *.h)

BINS = hw1 djikstras_hw2 mst_hw3

.PHONY: app clean hw1 djikstras_hw2 mst_hw3

djikstras_hw2: $(OBJ_DIR)graph.o $(OBJ_DIR)pqueue.o $(OBJ_DIR)shortestpath.o $(OBJ_DIR)djikstras_hw2.o 
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)$@

mst_hw3: $(OBJ_DIR)graph.o $(OBJ_DIR)mst_hw3.o 
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)$@

$(OBJ_DIR)djikstras_hw2.o: djikstras_hw2.cpp
	$(CC) $(INCLUDE_DIR) -c djikstras_hw2.cpp $(CFLAGS) -o $(OBJ_DIR)djikstras_hw2.o

$(OBJ_DIR)mst_hw3.o: mst.cpp
	$(CC) $(INCLUDE_DIR) -c mst.cpp $(CFLAGS) -o $(OBJ_DIR)mst_hw3.o

$(OBJ_DIR)graph.o: graph.cpp
	$(CC) $(INCLUDE_DIR) -c graph.cpp $(CFLAGS) -o $(OBJ_DIR)graph.o 

$(OBJ_DIR)pqueue.o: pqueue.cpp
	$(CC) $(INCLUDE_DIR) -c pqueue.cpp $(CFLAGS) -o $(OBJ_DIR)pqueue.o

$(OBJ_DIR)shortestpath.o: shortestpath.cpp
	$(CC) $(INCLUDE_DIR) -c shortestpath.cpp $(CFLAGS) -o $(OBJ_DIR)shortestpath.o