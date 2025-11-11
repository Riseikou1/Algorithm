#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rankv, rel;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rankv.resize(n, 0);
        rel.resize(n, 0);
    }

    pair<int,int> find(int x) {
        if (parent[x] == x) return {x, 0};
        auto res = find(parent[x]);
        parent[x] = res.first;
        rel[x] ^= res.second;
        return {parent[x], rel[x]};
    }

    bool unite(int x, int y, int t) {
        auto [px, rx] = find(x);
        auto [py, ry] = find(y);
        if (px == py) return (rx ^ ry) == t;
        if (rankv[px] < rankv[py]) swap(px, py);
        parent[py] = px;
        rel[py] = rx ^ ry ^ t;
        if (rankv[px] == rankv[py]) rankv[px]++;
        return true;
    }

    int relation(int x, int y) {
        auto [px, rx] = find(x);
        auto [py, ry] = find(y);
        if (px != py) return 3;
        return (rx ^ ry) ? 2 : 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w;
    cin >> w;
    string out;
    while (w--) {
        int n, m;
        cin >> n >> m;
        DSU dsu(n);

        for (int i = 0; i < m; i++) {
            int q, x, y;
            cin >> q >> x >> y;
            if (q == 1) {
                if (!dsu.unite(x, y, 0)) out += "0\n";
            } else if (q == 2) {
                if (!dsu.unite(x, y, 1)) out += "0\n";
            } else {
                out += to_string(dsu.relation(x, y)) + '\n';
            }
        }
    }
    cout << out;
    return 0;
}
