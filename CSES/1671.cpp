#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<pii> adj[n+1];
    vector<ll> dist(n+1, LLONG_MAX);
    vector<bool> flag(n+1);
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }

    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(dist[1], 1));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto vw:adj[u]) {
            ll v = vw.first, w = vw.second;
            if(flag[v]) continue;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<(i==n ? '\n' : ' ');
    return 0;
}