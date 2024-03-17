#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, q, x; cin >> n >> k >> q >> x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> adj[n+1];
    for(int i=0;i<k;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> flag(n+1);
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[x] = a[x];
    pq.push({dist[x], x});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto v:adj[u]) {
            if(flag[v]) continue;
            if(dist[v] > dist[u] + a[v]) dist[v] = dist[u] + a[v], pq.push({dist[v], v});
        }
    }

    while(q--) {
        int v; cin >> v;
        cout << dist[v] << '\n';
    }
    return 0;
}