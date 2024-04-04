#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

void bfs(vector<int>* adj, vector<int> &flag, int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto v:adj[u]) if(!flag[v]) flag[v] = (flag[u] == 1 ? 2 : 1), q.push(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> adj[n], flag(n);
    for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++) if(!flag[i]) bfs(adj, flag, i);

    bool ans = false;
    for(int i=0;i<n;i++) for(auto v:adj[i]) if(flag[i] == flag[v]) ans = true;
    cout << (ans ? "Gay found!\n" : "Gay not found!\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}

/*
2

3 3
0 1
1 2
0 2

4 2
0 1
2 3
*/