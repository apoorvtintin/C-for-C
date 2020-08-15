#include "shortestpath.h"

/***
 *  Methods for Class ShortestPath
**/
ShortestPath::ShortestPath(float density, int num_nodes):g(density, num_nodes),num_nodes(num_nodes) {
	//graph g(density, num_nodes);
}

void ShortestPath::setgraph() {
	g.set_random_graph();
}

void ShortestPath::vertices()  {
	//g.print_graph();
	cout<<g;
}
/*vector <int> path(int start, int dest) {

}*/
shortest_node ShortestPath::path_size(int start, int dest) {
	int cost = 0;
	int temp_cost = 0;
	shortest_node curr(start, 0);
	vector <int> done(num_nodes, 0);
	int count = 0;
	while(count <= num_nodes) {
		done.at(curr.node) = 1;
		for(int i = 0 ;i < num_nodes; i++) {
			if(done.at(i) == 1)
				continue;
			temp_cost = cost;
			if(g.get_edge_value(curr.node, i) != -1) {
				temp_cost = temp_cost + g.get_edge_value(curr.node, i);
				if(p.contains(i) != -1) {
					if(p.contains(i) > temp_cost) {
						p.chgPriority(i, temp_cost);
						p.updateWay(i, curr.way, curr.cost_way);
					}
				} else {
					shortest_node s(i, temp_cost, curr.way, curr.cost_way);
					p.insert(s);
				}
			}
		}
		cout<<"curr "<<curr.node;
		curr = p.minPriority();
		if(curr.node == -1)
			break;
		cost = curr.total_cost;
		curr.way.push_back(curr.node);
		curr.cost_way.push_back(curr.total_cost);
		count++;
		if(curr.node == dest) {
			return curr;
		}
	}
	curr.node = -1;
	curr.total_cost = -1;
	curr.way = vector<int>();
	return curr;
}
void ShortestPath::reinit() {
	p.reset();
}