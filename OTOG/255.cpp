#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++) {
        int v, u; cin >> v >> u;
        adj[u].push_back(v);
    }

    vector<int> bonus(n+1);
    while(m--) {
        vector<bool> flag(n+1);
        int x, y; cin >> x >> y;
        bonus[x] += y;
    }

    queue<int> q;
    vector<bool> flag(n+1);
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) if(!flag[v]) flag[v] = true, bonus[v] += bonus[u], q.push(v);
    }
    for(int i=1;i<=n;i++) cout << bonus[i] << '\n';
    return 0;
}