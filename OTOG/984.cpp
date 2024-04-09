#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int INF = INT_MAX;

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
    int n, m, q, k, p, s; cin >> n >> m >> q >> k >> p >> s;
    vector<pii> adj[n+1];
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    vector<int> dist1(n+1, INF), dist2(n+1, INF);
    vector<bool> flag1(n+1), flag2(n+1);
    dijkstra(adj, dist1, flag1, s);
    dijkstra(adj, dist2, flag2, p);

    while(q--) {
        int x; cin >> x;
        int ans = k - min(dist1[x], dist2[x]);
        if(dist1[p] > k) ans = k - dist1[x];
        cout << (ans >= 0 ? ans : -1) << '\n';
    }
    return 0;
}