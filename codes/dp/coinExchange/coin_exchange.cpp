#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int amount[] = {1, 5, 10, 21, 25};
unordered_map<int, int> memo;

int dfs(int total) {
    if (total == 0) return 0;
    if (memo.count(total)) return memo[total];

    int res = __INT_MAX__;
    for (int coin : amount) {
        if (coin <= total) {
            res = min(res, dfs(total - coin) + 1);
        }
    }
    return memo[total] = res;
}

int main() {
    cout << "Enter the amount : ";
    int n;
    cin >> n;
    int ans = dfs(n);
    if (ans == __INT_MAX__)
        cout << "Impossible\n";
    else
        cout << "Minimum coins: " << ans << "\n";
    return 0;
}
