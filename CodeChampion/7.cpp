#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v);
    }

    for (int u = 1; u <= n; ++u) {
        sort(adj[u].begin(), adj[u].end());
        cout << u << ": ";
        if (adj[u].empty()) cout << -1;
        for (auto& v: adj[u]) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}