#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

void dijkstra(vector<pii>* adj, vector<int> &dist, vector<bool> &flag, int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) if(!flag[v] and dist[v] > d + w) dist[v] = d + w, pq.push({dist[v], v});
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q, s, t; cin >> n >> m >> q >> s >> t;
    vector<pii> adj1[n+1], adj2[n+1];
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj1[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }

    vector<int> dist1(n+1, INT_MAX), dist2(n+1, INT_MAX);
    vector<bool> flag1(n+1), flag2(n+1);
    dijkstra(adj1, dist1, flag1, s);
    dijkstra(adj2, dist2, flag2, t);
    
    while(q--) {
        int x; cin >> x;
        cout << dist1[x] + dist2[x] << '\n';
    }
    return 0;
}