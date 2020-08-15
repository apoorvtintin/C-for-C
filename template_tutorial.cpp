#include <iostream>

using namespace std;

template <class T> //T is a generic type

T sum(const T data[], int size, T sum = 0) {
    for(int i = 0; i < size ; i ++) {
        cout<<data[i];
    }
    return sum;
}

int main() {
    double arr1[] = {2.1, 4.3, 5.5};
    int arr2[] = {1,2,3};
    cout<<sum(arr1, 3)<<'\n';
    cout<<sum(arr2, 3);
    return 0;
}