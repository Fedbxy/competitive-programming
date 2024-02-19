#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int N = 3.1e4, K = 1e2;
vector<pii> adj[N];
bool flag[N][K];
int dist[N][K];

void dijkstra(int s, int idx) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s][idx] = 0;
    pq.push(make_pair(dist[s][idx], s));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag[u][idx]) continue;
        flag[u][idx] = true;

        for(auto vw:adj[u]) {
            int v = vw.first, w = vw.second;
            if(flag[v][idx]) continue;
            if(dist[v][idx] > dist[u][idx] + w) {
                dist[v][idx] = dist[u][idx] + w;
                pq.push(make_pair(dist[v][idx], v));
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k,q;cin>>n>>m>>k>>q;
    for(int i=0;i<n;i++) for(int j=0;j<K;j++) dist[i][j] = INT_MAX;
    vector<int> res(k), idx(n);
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    for(int i=0;i<k;i++) cin>>res[i], idx[res[i]] = i;
    for(int i=0;i<k;i++) dijkstra(res[i], i);
    while(q--) {
        int s,x,t;cin>>s>>x>>t;
        cout<<dist[s][idx[x]] + dist[t][idx[x]]<<'\n';
    }
    return 0;
}