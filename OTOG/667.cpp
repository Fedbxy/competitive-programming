#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,s,t;cin>>n>>m>>s>>t;
    vector<pii> adj[n];
    vector<int> dist(n, INT_MAX);
    vector<bool> flag(n);
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(dist[s], s));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto vw:adj[u]) {
            int v = vw.first, w = vw.second;
            if(flag[v]) continue;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout<<dist[t]<<'\n';
    return 0;
}