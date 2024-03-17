#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    vector<pii> adj[n];
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> dist(n, INT_MAX);
    vector<bool> flag(n);
    vector<int> dir(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    dir[s] = s;
    pq.push({dist[s], s});
    while(!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) if(!flag[v] and dist[v] > d + w) dist[v] = d + w, pq.push({dist[v], v}), dir[v] = u;
    }

    vector<int> path;
    int cur = t;
    while(cur != dir[cur]) {
        path.push_back(cur);
        cur = dir[cur];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());

    cout << dist[t] << '\n';
    cout << path.size() << '\n';
    for(auto e:path) cout << e << ' ';
    cout << '\n';
    return 0;
}