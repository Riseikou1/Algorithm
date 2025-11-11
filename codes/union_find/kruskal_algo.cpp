#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

class UnionFind {
    int size;
    vector<int> rank;
    vector<int> parent;

public:
    UnionFind(int size) : size(size), rank(size, 1), parent(size) {
        for (int i = 0; i < size; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        if (rank[pu] < rank[pv]) swap(pu, pv);
        rank[pu] += rank[pv];
        parent[pv] = pu;
        return true;
    }
};

class Graph {
    int size;
    vector<string> vertex_data;
    vector<tuple<int, int, int>> edges;

public:
    Graph(int size) : size(size), vertex_data(size, "") {}

    void add_vertex_data(int vertex, const string &data) {
        vertex_data[vertex] = data;
    }

    void add_edge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    void kruskal() {
        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b) { return get<2>(a) < get<2>(b); });

        UnionFind uf(size);
        vector<tuple<int, int, int>> res;
        int total_weight = 0;

        for (auto &[u, v, w] : edges) {
            if (uf.unite(u, v)) {
                res.emplace_back(u, v, w);
                total_weight += w;
            }
        }

        cout << "Vertices\tWeight\n";
        for (auto &[u, v, w] : res) {
            cout << vertex_data[u] << " - " << vertex_data[v]
                 << "\t" << w << endl;
        }
        cout << "Total Weight : " << total_weight << endl;
    }
};

int main() {
    Graph g(7);
    vector<string> labels = {"A", "B", "C", "D", "E", "F", "G"};
    for (int i = 0; i < labels.size(); ++i) g.add_vertex_data(i, labels[i]);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 6, 10);
    g.add_edge(0, 2, 9);
    g.add_edge(1, 2, 8);
    g.add_edge(2, 3, 5);
    g.add_edge(2, 4, 2);
    g.add_edge(2, 6, 7);
    g.add_edge(3, 4, 3);
    g.add_edge(3, 5, 7);
    g.add_edge(4, 6, 6);
    g.add_edge(5, 6, 11);

    cout << string(44, '*') << "\nKruskal's Algorithm - Minimum Spanning Tree:\n"
         << string(44, '*') << endl;

    g.kruskal();
    return 0;
}