#include <iostream>
#include <limits>
#include <algorithm>
#define maxsize 1000
using namespace std;

int partition(int v[], int low, int high){
    int pivot = v[high];
    int i = low;
    int j = low;   
    int tmp;

    while(j < high){
        if(v[j] < pivot){
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            
            i++;
        }
        j++;
    }
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
    return i;
}

void quickSort(int v[], int low, int high){
    if (low >= high) return ;
    int pivot = partition(v, low, high);
    // by doing this shit first, it is kinda top-down shit.
    // cuz it starts from bigger subarray, and recursively goes down to the smaller pieces.
    quickSort(v, low, pivot - 1);
    quickSort(v, pivot + 1, high);
}

int main(){
    int temuujin[maxsize] = {5, 6, 9, 3, 5,2, 1, 3, 5, 8, 9, 6, 3, 1};
    int idx_size = sizeof(temuujin)/sizeof(temuujin[0]) - 1;
    quickSort(temuujin, 0, idx_size);
    for(int num : temuujin){
        if(num == 0) continue;
        cout << num << " " ;
    }
    cout << endl;
}
