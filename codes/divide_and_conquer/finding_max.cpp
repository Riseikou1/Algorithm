#include <iostream>
#define max_size 100
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int recurMax(int a[], int left, int right){
    int half;
    if(left == right){
        return a[left];
    }else{
        half = (left + right) / 2;
        return max(recurMax(a, left, half), recurMax(a, half + 1, right));
    }
}

int main(){
    int v[max_size] = {5, 3, 9, 2, 4, 8, 1, 6, 0, 7};
    cout << "maximum number is : " << recurMax(v, 0, 9) << "\n";
    return 0;
}
