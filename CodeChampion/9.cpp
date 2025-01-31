#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int k; cin >> k;
    vector<bool> suspend(n + 1);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        suspend[x] = true;
    }

    queue<int> q;
    vector<bool> flag(n + 1);
    q.emplace(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v: adj[u]) {
            if (flag[v] or suspend[v]) continue;
            flag[v] = true;
            q.emplace(v);
        }
    }
    cout << (flag[n] ? "YES" : "NO") << '\n';
    return 0;
}