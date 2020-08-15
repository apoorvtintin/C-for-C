#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class node {
    vector<int> edges;
    int size;
    int num_edges;
    public:
    int id;
    node(int size = 0, int id = 0):size(size),id(id) {
        num_edges = 0;
        for(int i = 0; i < size; i++) {
            edges.push_back(-1);
        }
    }
    node(const node& n)
        :num_edges(n.num_edges),size(n.size),edges(n.edges)
    {
        num_edges = 0;
        for(int i = 0; i < size; i++) {
            edges.push_back(-1);
        }
    }
    int set_edge(int to, int value) {
        edges.at(to) = value;
        return 0;
    }
    int return_edges(){
        return num_edges;
    }
    int edge_to(int to) {
        if(to >= size)
            return -1;
        return edges.at(to);
    }
    void print_edges() {
        for(int i = 0; i < size; i++) {
            cout<<"<-"<<edges.at(i)<<"  ";
        }
        cout<<"\n";
    }
    int get_id() {
        return id;
    }
    void set_id(int id) {
        this->id = id;
    }
    friend ostream& operator<<(ostream& out, const node& vertice);
};

    ostream& operator<<(ostream& out, const node& vertice) {

        for(int i = 0; i < vertice.size; i++) {
            out<<"<- "<< i << " "<<vertice.edges.at(i)<<"  ";
        }
        out<<"\n";
        return out;
    }

class graph {
        vector<node> nodes;
        double density;
        int num_nodes;
    public:
        graph(float density, int num_nodes)
            :density(density),num_nodes(num_nodes) 
        {
            cout<<"called?\n"<<this->density<<'\t'<<this->num_nodes;
            node vertice(this->num_nodes);
            for(int i = 0; i < this->num_nodes; i++) {
                vertice.id = i;
                nodes.push_back(vertice);
            }
        }
        int set_random_graph() {
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
        int V() {
            return num_nodes;
        }
        int E() {
            int total_edges = 0;
            for(uint i = 0; i < num_nodes; i++) {
                total_edges += nodes.at(i).return_edges();
            }
            return total_edges;
        }
        bool adjacent(const int& x,const int& y) {
            return (nodes.at(x).edge_to(y) > 0);
        }
        void print_graph() {
            for(uint i = 0; i < num_nodes; i++) {
                neighbors(i);
            }
        }
        void neighbors(int x){
            cout<<"vertice "<<x<<"\t"<<nodes.at(x)<<'\n';
        }
        int add_edge(int x, int y, int value) {
            nodes.at(x).set_edge(y, value);
            nodes.at(y).set_edge(x, value);
            return 0;
        }
        int delete_edge(int x, int y) {
            nodes.at(x).set_edge(y, -1);
            nodes.at(y).set_edge(x, -1);
            return 0;
        }
        int get_node_value(int x) {
            return nodes.at(x).get_id();
        }
        void set_node_value(int x, int val) {
            nodes.at(x).set_id(val);
        }
        void set_edge_value(int x, int y, int value) {
            add_edge(x, y, value);
        }
        int get_edge_value(int x, int y) {
            return nodes.at(x).edge_to(y);
        }
        friend ostream& operator<<(ostream& out, const graph& g);
};

ostream& operator<<(ostream& out, const graph& g) {
    for(uint i = 0; i < g.num_nodes; i++) {
        out<<"vertice "<<i<<"\t"<<g.nodes.at(i)<<'\n';
    }
    return out;
}

class shortest_node {
    public:
    vector<int> way;
    vector<int> cost_way;
    int node;
    int total_cost;
    shortest_node(int node = -1, int total_cost = 0, vector <int> way = vector<int>(), vector <int> cost_way = vector<int>())
                    :node(node), total_cost(total_cost), way(way) , cost_way(cost_way)
    { }
    friend ostream& operator<<(ostream& out, const shortest_node& g);
};

ostream& operator<<(ostream& out, const shortest_node& s) {
    out<< "node number "<< s.node << "cost is " << s.total_cost << "\nway is ";
    for(uint i = 0; i < s.way.size(); i++) {
        out<<" <-- vertice "<<i<<"\t"<<s.way.at(i)<<" cost till now "<< s.cost_way.at(i);
    }
    out<<'\n';
    return out;
}

class PriorityQueue {
    vector<shortest_node> minheap;
    int heap_size;
    void swap(int src, int dst) {
        shortest_node temp;
        temp = minheap.at(dst);
        minheap.at(dst) = minheap.at(src);
        minheap.at(src) = temp;
    }
    inline int root_of(int index) {
        return index/2;
    }
    inline int leaf_left(int index) {
        return (2 * index) - 1;
    }
    inline int leaf_right(int index) {
        return (2 * index) + 1;
    }
    inline bool is_root(int index) {
        return index == 1;
    }
    public:
        PriorityQueue() {
            heap_size = 0;
            shortest_node temp;
            minheap.push_back(temp);
        }
        void insert(const shortest_node& node) {
            minheap.push_back(node);
            int cursor = heap_size;
            place_val(cursor);
            heap_size++;
            //heapify();
        }
        shortest_node remove() {
            shortest_node ret;
            if(heap_size <=0) {
                return ret;
            }
            ret = minheap.at(1);
            swap(heap_size, 1);
            minheap.pop_back();
            heap_size--;
            int cursor = 1;
            heapify();
            return ret;
        }
        int size() {
            return minheap.size();
        }
        void place_val(int index) {
            while(minheap.at(root_of(index)).total_cost > minheap.at(index).total_cost) {
                if (is_root(index) == true)
                    break;
                swap(root_of(index), index);
                index = root_of(index);
            }
            return;
        }
        void heapify() {
            for(int i = 1; i <= heap_size; i++ ) {
                place_val(i);
            }
        }
        void print_heap() {
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

        int chgPriority(int node_number, int cost) {
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

        int updateWay(int node_number, vector <int> node, vector <int> cost_till_now) {
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
        shortest_node minPriority() {
            return remove();
        }
        int contains(int node_number) {
            for(int i = 1 ;i < minheap.size();i++) {
                if (minheap.at(i).node == node_number) {
                    return minheap.at(i).total_cost;
                }
            }
            return -1;
        }
        void reset() {
            minheap.clear();
            heap_size = 0;
            shortest_node temp;
            minheap.push_back(temp);
        }
        friend ostream& operator<<(ostream& out, const PriorityQueue& p);
};

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

class ShortestPath {
    graph g;
    PriorityQueue p;
    int num_nodes;
    float density;
    public:
    ShortestPath(float density = 0.1, int num_nodes = 50):num_nodes(num_nodes),density(density),g(density, num_nodes) {
        //graph g(density, num_nodes);
    }

    void setgraph() {
        g.set_random_graph();
    }

    void vertices()  {
        //g.print_graph();
        cout<<g;
    }
    /*vector <int> path(int start, int dest) {

    }*/
    shortest_node path_size(int start, int dest) {
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
    void reinit() {
        p.reset();
    }
};

