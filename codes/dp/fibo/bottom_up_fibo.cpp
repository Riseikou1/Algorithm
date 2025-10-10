#include <iostream>
#include <vector>
using namespace std;

int fibo(int n){
    vector<int> temuujin(n + 1, 0);
    temuujin[1] = 1;
    temuujin[2] = 1;

    if(n <= 2) return temuujin[n];

    for(int i = 3; i < n; i ++){
        temuujin[i] = temuujin[i - 1] + temuujin[i - 2];
    }
    return temuujin[n - 1];
}

int advanced_fibo(int n){
    if(n <= 2) return 1;
    int prev = 0;
    int cur = 1;
    for(int i = 3; i <= n; i++){
        int tmp = cur;
        cur += prev;
        prev = tmp;
    }
    return prev;
}

int main(){
    int n;
    cout << "Enter the pos : ";  // 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
    cin >> n;

    cout << "The fibonacci number at " << n << " is : " << fibo(n) << "\n";
    cout << "The fibonacci number at " << n << " is : " << fibo(n) << "\n";

    return 0;
}