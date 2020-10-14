#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;
// graph.h
#ifndef GRAPH_H // include guard
#define GRAPH_H

class node {
	private:
		vector<int> edges;
		int num_edges;
		int size;
    public:
		int id;
		node(int size = 0, int id = 0);
		node(const node& n);
		int set_edge(int to, int value);
		int return_edges();
		int edge_to(int to);
		void print_edges();
		int get_id();
		void set_id(int id);
		friend ostream& operator<<(ostream& out, const node& vertice);
};

class graph {
	private:
        vector<node> nodes;
		int num_nodes;
        double density;
    public:
        graph( int num_nodes, float density = 0);
		graph(string path);
        int set_random_graph();
        int V();
        int E();
        bool adjacent(const int& x,const int& y);
        void print_graph();
        void neighbors(int x);
        int add_edge(int x, int y, int value);
        int delete_edge(int x, int y);
        int get_node_value(int x);
        void set_node_value(int x, int val);
        void set_edge_value(int x, int y, int value);
        int get_edge_value(int x, int y);
		int get_num_nodes();
        friend ostream& operator<<(ostream& out, const graph& g);
};

class shortest_node {
    public:
    vector<int> way;
    vector<int> cost_way;
    int node;
    int total_cost;
    shortest_node(int node = -1, int total_cost = 0, vector <int> way = vector<int>(), vector <int> cost_way = vector<int>());
    friend ostream& operator<<(ostream& out, const shortest_node& g);
};

#endif /*GRAPH_H*/