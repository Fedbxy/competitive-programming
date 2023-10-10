#include <bits/stdc++.h>

using namespace std;

const int N=110;
vector<int> dist(N,INT_MAX);
bool flag[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int start=0;
    dist[start]=0;
    pq.push({dist[start],start});
    int ans=0;
    while(!pq.empty()){
        int W=pq.top().first,u=pq.top().second;
        pq.pop();
        if(flag[u]) continue;
        flag[u]=true;ans+=W;
        for(auto vw:adj[u]){
            int v=vw.first,w=vw.second;
            if(flag[v]) continue;
            if(dist[v]>w) dist[v]=w,pq.push({dist[v],v});
        }
    }
    cout<<ans<<'\n';
    return 0;
}
