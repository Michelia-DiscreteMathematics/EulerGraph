#include "Graph.h"
using namespace std;

int main(){
	cout<<endl;
	Graph undirected;
	undirected.get_node();
	undirected.init_matrix();
	undirected.get_degree();
	undirected.check_path();
	undirected.print_info();
	undirected.get_path();
	cout<<endl;
	undirected.print_info();
	return 0;
}