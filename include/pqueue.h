#include "graph.h"

// graph.h
#ifndef PQUEUE_H // include guard
#define PQUEUE_H

class PriorityQueue {
	private:
		vector<shortest_node> minheap;
		int heap_size;
		void swap(int src, int dst);
		inline int root_of(int index);
		inline int leaf_left(int index);
		inline int leaf_right(int index);
		inline bool is_root(int index);
    public:
        PriorityQueue();
        void insert(const shortest_node& node);
        shortest_node remove();
        int size();
        void place_val(int index);
        void heapify();
        void print_heap();
        int chgPriority(int node_number, int cost);
        int updateWay(int node_number, vector <int> node, vector <int> cost_till_now);
        shortest_node minPriority();
        int contains(int node_number);
        void reset();

        friend ostream& operator<<(ostream& out, const PriorityQueue& p);
};
#endif /* PQUEUE_H */