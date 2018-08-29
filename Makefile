all: main

main: main.cpp list.h iterator.h node.h
	g++ -std=c++11 main.cpp -o main
