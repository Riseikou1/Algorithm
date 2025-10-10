#include <iostream>
#include <vector>
using namespace std;
vector<long long> fib_lengths;

char findChar(int k, long long p) {
    if (k == 1) return 'b';
    if (k == 2) return 'a';
    long long len_prev = fib_lengths[k - 1];

    if (p < len_prev) {
        return findChar(k - 1, p);
    } else {
        return findChar(k - 2, p - len_prev);
    }
}

int main() {
    fib_lengths.push_back(0); 
    fib_lengths.push_back(1); 
    fib_lengths.push_back(1); 

    for (int i = 3; i <= 48; i++) {
        fib_lengths.push_back(fib_lengths[i - 1] + fib_lengths[i - 2]);
    }
    
    int t;
    cin >> t;
    while (t--) {
        int k;
        long long p;
        cin >> k >> p;
        cout << findChar(k, p) << "\n";
    }
    return 0;
}