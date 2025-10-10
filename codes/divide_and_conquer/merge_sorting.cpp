#include <iostream>
#define maxsize 100
using namespace std;

void merge(int a[], int left, int mid, int right){   
    int tmp[maxsize];
    for(int i=left; i<=right;i++){
        tmp[i] = a[i];
    }
    int i, k, j;
    i = k = left;
    j = mid + 1;
    while(i<= mid && j <=right){
        if(tmp[i] <= tmp[j]){
            a[k++] = tmp[i++];
        }
        else{
            a[k++] = tmp[j++];
        }
    }
    while(i <= mid && k<=right){
        a[k++] = tmp[i++];
    }
    while(j <=right && k<=right){
        a[k++] = tmp[j++];
    }

}
void mergeSort(int v[], int left, int right){
    // this is the dividing part.
    // base case is there is only one element.
    // and it starts bubbling up to bigger subarrays, while sorting them in-place.
    if (left == right) return ;
    // this shit returns just one num. and its parent receives 2nums from its succeding recrusion calls, and so on.
    int mid = (left + right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}

void iter_mergeSort(int v[], int n){  // bottom up.
    int size = 1;  // start from just a single element.
    while(size < n){
        for(int i = 0;i < n; i += 2*size){  // starting indices also will be increased by 2 times size, since that will be the next starting point. 
            int low = i;
            int mid = low + size - 1;
            int high = min(i + 2 * size - 1, n -1);
            if(mid >= n - 1) break;  // mid equals last idx means, there is only one element.
            merge(v, low, mid, high);
        }
        size *= 2;  // the reason why're we multiplying this by 2 is, at each iteration we're joining 2 shits, thus, increasing the current array size by 2times.
    }
}

int main(){
    int temuujin[maxsize] = {5, 6, 9, 3, 5,2, 1, 3, 5, 8, 9, 6, 3, 1};
    int idx_size = sizeof(temuujin)/sizeof(temuujin[0]) - 1;
    mergeSort(temuujin, 0, idx_size);
    //iter_mergeSort(temuujin, idx_size);
    for(int num : temuujin){
        if(num == 0) continue;
        cout << num << " " ;
    }
    cout << endl;
}
