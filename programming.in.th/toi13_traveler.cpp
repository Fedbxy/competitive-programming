#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

void dijkstra(vector<pii> *adj, vector<int> &dist, vector<bool> &flag, int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) {
            if(flag[v]) continue;
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int s, t, k; cin >> s >> t >> k;
    vector<pii> adj[n];
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
    vector<bool> flag1(n), flag2(n);
    dijkstra(adj, dist1, flag1, s);
    dijkstra(adj, dist2, flag2, t);

    vector<int> sel;
    for(int i=0;i<n;i++) if(dist1[i] <= k) sel.push_back(i);
    sort(sel.begin(), sel.end());
    int idx, mn = INT_MAX;
    for(auto e:sel) {
        if(dist2[e] < mn) {
            idx = e;
            mn = dist2[e];
        }
    }
    cout << idx << ' ' << dist1[idx] << ' ' << dist2[idx] << '\n'; 
    return 0;
}