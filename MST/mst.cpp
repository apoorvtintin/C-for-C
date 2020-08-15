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
