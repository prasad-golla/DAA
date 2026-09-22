#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
    vector<int> parent, rank_;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank_.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rank_[a] < rank_[b])
            swap(a, b);

        parent[b] = a;

        if (rank_[a] == rank_[b])
            rank_[a]++;

        return true;
    }
};

int main() {
    int n, m;
    cout<<"enter no of vertices and edges";
    cin >> n >> m; // vertices, edges

    vector<Edge> edges(m);
    cout<<"enter graph"<<endl;

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mstWeight = 0;
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

    if ((int)mst.size() != n - 1) {
        cout << "MST not possible: graph is disconnected\n";
        return 0;
    }

    cout << "MST Weight: " << mstWeight << '\n';
    cout << "MST Edges:\n";

    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v
             << " : " << edge.weight << '\n';
    }

    return 0;
}