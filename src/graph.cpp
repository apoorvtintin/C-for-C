#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

#include "graph.h"

/***
 *  Methods for Class node
**/
node::node(int size, int id):size(size),id(id) {
	num_edges = 0;
	for(int i = 0; i < size; i++) {
		edges.push_back(-1);
	}
}
node::node(const node& n)
	:edges(n.edges),num_edges(n.num_edges),size(n.size)
{
	num_edges = 0;
	for(int i = 0; i < size; i++) {
		edges.push_back(-1);
	}
}
int node::set_edge(int to, int value) {
	edges.at(to) = value;
	return 0;
}
int node::return_edges(){
	return num_edges;
}
int node::edge_to(int to) {
	if(to >= size)
		return -1;
	return edges.at(to);
}
void node::print_edges() {
	for(int i = 0; i < size; i++) {
		cout<<"<-"<<edges.at(i)<<"  ";
	}
	cout<<"\n";
}
int node::get_id() {
	return id;
}
void node::set_id(int id) {
	this->id = id;
}

ostream& operator<<(ostream& out, const node& vertice) {

	for(int i = 0; i < vertice.size; i++) {
		out<<"<- "<< i << " "<<vertice.edges.at(i)<<"  ";
	}
	out<<"\n";
	return out;
}

/***
 *  Methods for Class graph
**/
graph::graph(float density, int num_nodes)
	:density(density),num_nodes(num_nodes) 
{
	cout<<"called?\n"<<this->density<<'\t'<<this->num_nodes;
	node vertice(this->num_nodes);
	for(int i = 0; i < this->num_nodes; i++) {
		vertice.id = i;
		nodes.push_back(vertice);
	}
}
int graph::set_random_graph() {
	srand(time(0));
	for(uint i = 0; i < num_nodes; i++) {
		for(uint j = i; j < num_nodes; j++) {
			if(i == j)
				continue;
			float prob = (static_cast<double>(rand() % 101)) / 100;
			//cout<<"prob "<<prob<<endl;
			if(prob < density) {
				//cout<<"yes\n";
				int value = (rand() % 9) + 1;
				//cout<<"value "<<value<<endl;
				nodes.at(i).set_edge(j, value);
				nodes.at(j).set_edge(i, value);
			}
		}
	}
	return 0;
}
int graph::V() {
	return num_nodes;
}
int graph::E() {
	int total_edges = 0;
	for(uint i = 0; i < num_nodes; i++) {
		total_edges += nodes.at(i).return_edges();
	}
	return total_edges;
}
bool graph::adjacent(const int& x,const int& y) {
	return (nodes.at(x).edge_to(y) > 0);
}
void graph::print_graph() {
	for(uint i = 0; i < num_nodes; i++) {
		neighbors(i);
	}
}
void graph::neighbors(int x){
	cout<<"vertice "<<x<<"\t"<<nodes.at(x)<<'\n';
}
int graph::add_edge(int x, int y, int value) {
	nodes.at(x).set_edge(y, value);
	nodes.at(y).set_edge(x, value);
	return 0;
}
int graph::delete_edge(int x, int y) {
	nodes.at(x).set_edge(y, -1);
	nodes.at(y).set_edge(x, -1);
	return 0;
}
int graph::get_node_value(int x) {
	return nodes.at(x).get_id();
}
void graph::set_node_value(int x, int val) {
	nodes.at(x).set_id(val);
}
void graph::set_edge_value(int x, int y, int value) {
	add_edge(x, y, value);
}
int graph::get_edge_value(int x, int y) {
	return nodes.at(x).edge_to(y);
}

ostream& operator<<(ostream& out, const graph& g) {
    for(uint i = 0; i < g.num_nodes; i++) {
        out<<"vertice "<<i<<"\t"<<g.nodes.at(i)<<'\n';
    }
    return out;
}


/***
 *  Methods for Class shortest_node
**/
shortest_node::shortest_node(int node, int total_cost, vector <int> way, vector <int> cost_way)
				: way(way) , cost_way(cost_way), node(node), total_cost(total_cost)
{ }


ostream& operator<<(ostream& out, const shortest_node& s) {
    out<< "node number "<< s.node << "cost is " << s.total_cost << "\nway is ";
    for(uint i = 0; i < s.way.size(); i++) {
        out<<" <-- vertice "<<i<<"\t"<<s.way.at(i)<<" cost till now "<< s.cost_way.at(i);
    }
    out<<'\n';
    return out;
}


