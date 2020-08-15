#include "graph.h"
#include "pqueue.h"

class ShortestPath {
	private:
		graph g;
		PriorityQueue p;
		int num_nodes;
    public:
		ShortestPath(float density = 0.1, int num_nodes = 50);
		void setgraph();
		void vertices();
		shortest_node path_size(int start, int dest);
		void reinit();
};