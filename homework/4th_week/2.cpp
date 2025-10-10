#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        Fenwick ft(n);
        long long inversions = 0;

        // Process from left to right
        for (int i = 0; i < n; i++) {
            // Count how many greater elements have appeared before
            inversions += i - ft.query(a[i]);
            ft.update(a[i], 1);
        }

        cout << inversions << "\n";
    }
    return 0;
}
