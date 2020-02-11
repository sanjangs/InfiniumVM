CC = g++
SRC = ./src/main.cpp
EXE = ./bin/ivm.exe

all:
	$(CC) $(SRC) -o $(EXE)
