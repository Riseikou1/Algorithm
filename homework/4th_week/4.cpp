#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Fenwick {
    vector<int> bits;
    int n;
    Fenwick(int n) : n(n), bits(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bits[idx] += val;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bits[idx];
        }
        return sum;
    }
};

int main() {
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        int tmp;

        unordered_map<int, int> a_idx;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            a_idx[tmp] = i + 1; // FIX: use 1-based index
        }

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            b[i] = a_idx[tmp];
        }

        Fenwick ft(n);
        long long inversions = 0;
        for (int i = 0; i < n; i++) {
            inversions += i - ft.query(b[i]);
            ft.update(b[i], 1);
        }
        cout << inversions << "\n";
    }

    return 0;
}
