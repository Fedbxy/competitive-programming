#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;

const int N = 510;
vector<pii> adj[N];
vector<vector<ll>> dist(N, vector<ll>(N, LLONG_MAX));

void dijkstra(int s, int idx) {
    vector<bool> flag(N);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[s][idx] = 0;
    pq.push(make_pair(dist[s][idx], s));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto vw:adj[u]) {
            int v = vw.first, w = vw.second;
            if(flag[v]) continue;
            if(dist[v][idx] > dist[u][idx] + w) {
                dist[v][idx] = dist[u][idx] + w;
                pq.push(make_pair(dist[v][idx], v));
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    for(int i=1;i<=n;i++) dijkstra(i, i);

    while(q--) {
        int u,v;cin>>u>>v;
        cout<<(dist[v][u] == LLONG_MAX ? -1 : dist[v][u])<<'\n';
    }
    return 0;
}