#include "pqueue.h"

void PriorityQueue::swap(int src, int dst) {
	shortest_node temp;
	temp = minheap.at(dst);
	minheap.at(dst) = minheap.at(src);
	minheap.at(src) = temp;
}
inline int PriorityQueue::root_of(int index) {
	return index/2;
}
inline int PriorityQueue::leaf_left(int index) {
	return (2 * index) - 1;
}
inline int PriorityQueue::leaf_right(int index) {
	return (2 * index) + 1;
}
inline bool PriorityQueue::is_root(int index) {
	return index == 1;
}
PriorityQueue::PriorityQueue() {
	heap_size = 0;
	shortest_node temp;
	minheap.push_back(temp);
}
void PriorityQueue::insert(const shortest_node& node) {
	minheap.push_back(node);
	int cursor = heap_size;
	place_val(cursor);
	heap_size++;
	//heapify();
}
shortest_node PriorityQueue::remove() {
	shortest_node ret;
	if(heap_size <=0) {
		return ret;
	}
	ret = minheap.at(1);
	swap(heap_size, 1);
	minheap.pop_back();
	heap_size--;
	heapify();
	return ret;
}
int PriorityQueue::size() {
	return minheap.size();
}
void PriorityQueue::place_val(int index) {
	while(minheap.at(root_of(index)).total_cost > minheap.at(index).total_cost) {
		if (is_root(index) == true)
			break;
		swap(root_of(index), index);
		index = root_of(index);
	}
	return;
}
void PriorityQueue::heapify() {
	for(int i = 1; i <= heap_size; i++ ) {
		place_val(i);
	}
}
void PriorityQueue::print_heap() {
	int mul = 1;
	int flag = 1;
	int level = 0;
	cout<< "\nstartiing print heap\n";
	for(int i = 0 ;i < minheap.size();i++) {
		cout<<minheap.at(i) << '\t';
		if(flag == i) {
			mul = mul * 2;
			flag = flag + mul;
			cout<<"next level "<< level<< '\n';
			level++;
		}
	}
}

int PriorityQueue::chgPriority(int node_number, int cost) {
	for(int i = 1 ;i < minheap.size();i++) {
		if (minheap.at(i).node == node_number) {
			minheap.at(i).total_cost = cost;
			//TODO handle way also
			heapify();
			return 0;
		}
	}
	return -1;
}

int PriorityQueue::updateWay(int node_number, vector <int> node, vector <int> cost_till_now) {
	for(int i = 1 ;i < minheap.size();i++) {
		if (minheap.at(i).node == node_number) {
			minheap.at(i).way.clear();
			minheap.at(i).cost_way.clear();
			minheap.at(i).way = node;
			minheap.at(i).cost_way = cost_till_now;
			return 0;
		}
	}
	return -1;
}
shortest_node PriorityQueue::minPriority() {
	return remove();
}
int PriorityQueue::contains(int node_number) {
	for(int i = 1 ;i < minheap.size();i++) {
		if (minheap.at(i).node == node_number) {
			return minheap.at(i).total_cost;
		}
	}
	return -1;
}
void PriorityQueue::reset() {
	minheap.clear();
	heap_size = 0;
	shortest_node temp;
	minheap.push_back(temp);
}

ostream& operator<<(ostream& out, const PriorityQueue& p) {
    int mul = 1;
    int flag = 1;
    int level = 0;
    out<< "\nstartiing print heap\n";
    for(int i = 0 ;i < p.minheap.size();i++) {
        out<<p.minheap.at(i) << '\t';
        if(flag == i) {
            mul = mul * 2;
            flag = flag + mul;
            out<<"next level "<< level<< '\n';
            level++;
        }
    }
    return out;
}