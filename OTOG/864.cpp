#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, q, x; cin >> n >> k >> q >> x;
    vector<int> energy(n+1);
    vector<pii> adj[n+1];
    for(int i=1;i<=n;i++) cin >> energy[i];
    for(int i=0;i<k;i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, energy[v]);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> flag(n+1);
    vector<int> dist(n+1, INT_MAX);
    dist[x] = energy[x];
    pq.emplace(dist[x], x);
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

    while(q--) {
        int v; cin >> v;
        cout << dist[v] << '\n';
    }
    return 0;
}