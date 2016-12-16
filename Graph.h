#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include <ctime>


class Graph
{
private:
	bool path,circuit;
	int node;
	int total_degree;
	std::vector<std::vector<int>> matrix;
	std::vector<int> degree;
	std::vector<int> line;

public:
	void get_node();
	void init_matrix();
	void get_degree();
	int check_path();
	void get_path();
	void print_info();

};

#endif