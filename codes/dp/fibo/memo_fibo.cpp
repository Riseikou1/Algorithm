#include <iostream>
#define max_size 100
using namespace std;
int memo[max_size];

int recFib(int n){
    if(memo[n] >= 0){
        return memo[n];
    }
    if(n <= 1){
        memo[n] = n;
        return n;
    }
    memo[n] = recFib(n - 1) + recFib(n - 2);
    return memo[n];
}

int fibo(int n){
    for(int i = 0; i <= n; i ++){
        memo[i] = -1;
    }
    return recFib(n);
}

int main(){
    cout << "Enter n num : ";
    int n;
    cin >> n;
    cout << "Fibonacci number at " << n << " is : " << fibo(n) << "\n";
    return 0;
}