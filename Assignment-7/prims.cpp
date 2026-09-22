#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

   
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    vector<bool> visited(n + 1, false);
    vector<tuple<int, int, int>> mst;

    int mstWeight = 0;
    pq.push({0, 1, -1});

    while (!pq.empty()) {
        auto [weight, node, parent] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        mstWeight += weight;

        if (parent != -1)
            mst.push_back({parent, node, weight});

        for (auto [nextNode, nextWeight] : graph[node]) {
            if (!visited[nextNode]) {
                pq.push({nextWeight, nextNode, node});
            }
        }
    }

    if ((int)mst.size() != n - 1) {
        cout << "MST not possible: graph is disconnected\n";
        return 0;
    }

    cout << "MST Weight: " << mstWeight << '\n';
    cout << "MST Edges:\n";

    for (auto [u, v, weight] : mst) {
        cout << u << " - " << v << " : " << weight << '\n';
    }

    return 0;
}