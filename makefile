install: EulerGraph

EulerGraph: Graph.o main.o
	g++ -g -o EulerGraph Graph.o main.o -std=c++11

main.o:
	g++ -g -c -o main.o main.cpp -std=c++11

Graph.o: Graph.h Graph.cpp
	g++ -g -c -o Graph.o Graph.cpp -std=c++11

clean:
	rm Graph.o main.o EulerGraph