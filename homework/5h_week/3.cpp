#include <iostream>
#include <vector>
using namespace std;

int binCoeff(int n, int k) {
    vector<int> B(k + 1, 0);
    B[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            B[j] = (B[j] + B[j - 1]) % 10007;
        }
    }
    return B[k];
}

int main() {
    int w;
    cin >> w;
    while (w--) {
        int n, k;
        cin >> n >> k;
        cout << binCoeff(n, k) << endl;
    }
    return 0;
}
