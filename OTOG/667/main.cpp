#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int N=1e4+10;
vector<pii> adj[N];
bool flag[N];
vector<int> dist(N,INT_MAX);

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,s,t;cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty()){
        int W=pq.top().first,u=pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u]=true;

        for(auto vw:adj[u]){
            int v=vw.first,w=vw.second;
            if(!flag[v] and W+w<dist[v]){
                dist[v]=W+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<dist[t]<<'\n';
    return 0;
}