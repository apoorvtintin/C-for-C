#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class heap {
    vector<int> minheap;
    int heap_size;
    void swap(int src, int dst) {
        int temp;
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
        heap() {
            heap_size = 0;
            int temp;
            minheap.push_back(temp);
        }
        void insert(const int& node) {
            minheap.push_back(node);
            int cursor = heap_size;
            place_val(cursor);
            heap_size++;
            //heapify();
        }
        int remove() {
            int ret;
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
            while(minheap.at(root_of(index)) > minheap.at(index)) {
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

};

int main() {
    heap h;
    h.insert(180);
    h.print_heap();
    h.insert(2);
    h.print_heap();
    h.insert(5);
    h.print_heap();
    h.insert(7);
    h.print_heap();
    h.insert(-34);
    h.print_heap();
    h.insert(-6);
    h.print_heap();
    h.insert(55);
    h.print_heap();
    h.insert(45);
    h.print_heap();
    h.insert(0);
    h.print_heap();
    h.insert(-3);
    h.print_heap();
    h.insert(9);
    h.print_heap();

    return 0;
}