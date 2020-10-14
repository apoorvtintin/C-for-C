#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <queue>

using namespace std;

#include "graph.h"

class compare_kruskal {
	public:
		bool operator() (vector<int> v1, vector<int> v2) {
			return v1.at(2) > v2.at(2);
		}
};
//TODO curr to from write all
class mst {
	private:
		string path;
		graph g;
		

		bool isSetComplete(vector<int> set) {
			for(vector<int>::iterator i = set.begin(); i != set.end(); i++) {
				if(*i == 0) {
					return false;
				}
			}
			return true;
		}
	public:
		mst(string path):path(path),g(path) {
			cout<<"constructor callewd\n";
		}

		void mst_kruskal() {
			int cost = 0;
			cout<<"graph is\n"<<g;
			graph mst_final(g.get_num_nodes());
			priority_queue<vector<int>, vector<vector<int>>, compare_kruskal> pq;
			vector<int> closed_set(g.get_num_nodes(), 0);
			int curr = 0;
			int value;
			closed_set.at(curr) = 1;
			
			while(!isSetComplete(closed_set)) {
				
				for(int i = 0; i < g.get_num_nodes(); i++) {
					if(closed_set.at(i) == 0 && i != curr) {
						value = g.get_edge_value(curr, i);
						if(value >= 0) {
							vector<int> temp_node(3,0);
							temp_node.at(0) = curr;
							temp_node.at(1) = i;
							temp_node.at(2) = value;
							pq.push(temp_node);
						}
					}
				}
				vector<int> next_node;
				if(pq.empty()) {
					cout<<"incomplete mst because unconnected graph cost is"<< cost<<"\n";
					cout<< mst_final;
					return;
				}
				next_node = pq.top();
				pq.pop();
				closed_set.at(curr) = 1;
				while(closed_set.at(next_node.at(1)) == 1) {
					if(pq.empty()) {
						cout<<"complete mst because unconnected graph cost is"<< cost<<"\n";
						cout<< mst_final;
						return;
					}
					next_node = pq.top();
					pq.pop();
				}
				mst_final.set_edge_value(next_node.at(0), next_node.at(1), next_node.at(2));
				cost += next_node.at(2);

				curr = next_node.at(1);
			}
			cout<<"complete mst because unconnected graph cost is"<< cost<<"\n";
			cout<< mst_final;
			return;
		}

		/*graph mst_prims() {
			graph mst_final(g.get_num_nodes());
			priority_queue
		}*/
};


int main() {
	string path = "data/hw3.txt";
	mst mst1(path);
	mst1.mst_kruskal();
	return 0;
}