#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

void dijkstra(vector<pii> *adj, vector<vector<int>> &dist, int s, int idx) {
    vector<bool> flag(dist.size());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s][idx] = 0;
    pq.emplace(dist[s][idx], s);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) {
            if(flag[v]) continue;
            if(dist[v][idx] > d + w) {
                dist[v][idx] = d + w;
                pq.emplace(dist[v][idx], v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<pii> adj[n+1];
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> shop(k);
    unordered_map<int, int> idx;
    for(int i=0;i<k;i++) cin >> shop[i], idx[shop[i]] = i;
    
    vector<vector<int>> dist(n+1, vector<int> (k, INT_MAX));
    for(int i=0;i<k;i++) dijkstra(adj, dist, shop[i], i);

    while(q--) {
        int s, x, t; cin >> s >> x >> t;
        cout << dist[s][idx[x]] + dist[t][idx[x]] << '\n';
    }
    return 0;
}