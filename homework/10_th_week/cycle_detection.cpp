#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;

    UnionFind(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false; // cycle detected

        if (size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        UnionFind uf(n);
        set<pair<int,int>> seen;
        bool hasCycle = false;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);

            if (seen.count({u, v})) continue;
            seen.insert({u, v});

            if (!uf.unite(u, v)) hasCycle = true;
        }

        cout << (hasCycle ? 1 : 0) << "\n";
    }

    return 0;
}
