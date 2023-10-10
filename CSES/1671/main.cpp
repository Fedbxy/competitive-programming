#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;
using ll=long long int;
using pli=pair<ll,int>;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int n,m;cin>>n>>m;
    vector<pii> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    vector<ll> dist(n+1,LLONG_MAX);
    vector<bool> flag(n+1);
    priority_queue<pli,vector<pli>,greater<pli>> pq;

    int s=1;
    dist[s]=0;pq.push({dist[s],s});
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();

        if(flag[u])continue;
        flag[u]=true;

        for(auto vw:adj[u]){
            int v=vw.first,w=vw.second;
            if(!flag[v] and dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i];
        if(i!=n)cout<<' ';
        else cout<<'\n';
    }
    return 0;
}