#include <iostream>
#define maxsize 100
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

void merge(int a[], int left, int mid, int right){
    int tmp[maxsize];
    for(int i = left; i <= right; i++){
        tmp[i] = a[i];
    }
    int k = left;  // pointer for sorted array.
    int i = left;  // left sorted portion.
    int j = mid + 1; // right sorted portion.

    while (i <= mid && j <= right){
        if (tmp[i] <= tmp[j]){
            a[k++] = tmp[i++];
        }
        else{
            a[k++] = tmp[j++];
        }
    }
    while(i <= mid){
        a[k++] = tmp[i++];
    }
    while(j <= right){
        a[k ++] = tmp[j++];
    }
}

void iter_mergeSort(int v[], int n){  // n is size of array.
    int size = 1;
    while (size < n){
        for(int i = 0; i < n; i += 2 * size){
            int low = i;
            int mid = low + size - 1;
            int high = min(low + 2 * size - 1, n - 1);
            if (mid >= n - 1) break;
            merge(v, low, mid, high);
        }
        size *= 2;
    }
}

void mergeSort(int v[], int left, int right){
    if (left == right) return;
    int mid = (left + right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}

int main(){
    int temuujin[maxsize] = {5, 6, 9, 11, 3, 5,2, 1, 3, 5, 8, 9, 6, 3, 1, 7};
    int idx_size = sizeof(temuujin)/sizeof(temuujin[0]) - 1;
    mergeSort(temuujin, 0, idx_size - 1);
    //iter_mergeSort(temuujin, idx_size);
    for(int num : temuujin){
        if(num == 0) continue;
        cout << num << " " ;
    }
    cout << endl;
}