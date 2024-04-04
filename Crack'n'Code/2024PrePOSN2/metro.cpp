#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pii> adj[n+m];
    for(int i=0;i<m;i++) {
        int st, w; cin >> st >> w;
        vector<int> node(st);
        for(int j=0;j<st;j++) cin >> node[j];
        for(int j=0;j<st;j++) adj[node[j]].emplace_back(n+i, w), adj[n+i].emplace_back(node[j], 0);
        // for(int j=0;j<st;j++) for(int k=0;k<st;k++) if(j != k) adj[node[j]].emplace_back(node[k], w), adj[node[k]].emplace_back(node[j], w);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n+m, INT_MAX);
    vector<bool> flag(n+m);
    dist[0] = 0;
    pq.emplace(dist[0], 0);
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

    cout << (flag[n-1] ? dist[n-1] : -1) << '\n';
    return 0;
}