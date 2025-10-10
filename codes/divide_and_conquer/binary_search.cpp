#include <iostream>
using namespace std;

int binary_search(int a[], int left, int right, int value){
    if(left > right) return -1;

    int mid = (left + right) /2 ;
    if(a[mid] == value){
        return mid;
    }
    else if(a[mid] > value) {
        return binary_search(a, left, mid - 1, value);
    }
    else {
        return binary_search(a, mid + 1, right, value);
    }
}

int main(){
    int v[] = {1, 3, 4, 7, 9, 11, 15};
    int idx = sizeof(v) / sizeof(v[0]) - 1;
    cout << "Returning idx of element '11' : " << binary_search(v, 0, 6, 11) << endl;
    return 0;
}
