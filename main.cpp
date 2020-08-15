#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main() {
    float density;
    int num_nodes, start, dest;
    char exit = 'n';

    cout<<"enter density (float) and num_nodes (int)\n";
    cin>>density>>num_nodes;
    ShortestPath s(density, num_nodes);

    s.setgraph();
    s.vertices();

    do {
        cout<<"enter start, dest ";
        cin>> start >> dest;
        cout<<"cost is \t"<< s.path_size(start, dest);
        s.reinit();
        cout<<"\n exit? y/n";
        cin>>exit;
    } while(exit != 'y');
    return 0;
}