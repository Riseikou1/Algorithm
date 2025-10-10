#include <iostream>
using namespace std;

unsigned long long sumOfBits(unsigned long long n){
    unsigned long long total = 0;
    for (int L = 1; (1ULL << (L-1)) <= n; ++L) {
        unsigned long long start = 1ULL << (L-1);
        unsigned long long end = (1ULL << L) - 1;
        if (end > n) end = n;
        unsigned long long cnt = end - start + 1;
        total += cnt * L;
    }
    return total;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long n;
        cin >> n;
        cout << sumOfBits(n) << endl;
    }
    return 0;
}
