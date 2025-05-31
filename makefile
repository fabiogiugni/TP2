CC = g++
CFLAGS = -Wall -I include
SRC_DIR = src/
BIN_DIR = bin/
EXECUTABLE = $(BIN_DIR)tp2.out
SOURCE_FILES = $(SRC_DIR)main.cpp $(SRC_DIR)graph.cpp $(SRC_DIR)listaAdjacencia.cpp $(SRC_DIR)listaEncadeada.cpp 

all: 
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE_FILES)

clean:
	rm -rf $(BIN_DIR)*.out