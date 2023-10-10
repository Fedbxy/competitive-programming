#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;
using ll=long long int;
using pli=pair<ll,int>;

const int N=500+1;
vector<pii> adj[N];
ll dist[N][N];
bool flag[N][N];

void dijkstra(int s,int idx){
    priority_queue<pli,vector<pli>,greater<pli>> pq;

    dist[s][idx]=0;pq.push({dist[s][idx],s});
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();

        if(flag[u][idx])continue;
        flag[u][idx]=true;

        for(auto vw:adj[u]){
            int v=vw.first,w=vw.second;
            if(!flag[v][idx] and dist[u][idx]+w<dist[v][idx]){
                dist[v][idx]=dist[u][idx]+w;
                pq.push({dist[v][idx],v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int n,m,q;cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=LLONG_MAX;
        }
    }

    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        dijkstra(i,i);
    }

    while(q--){
        int s,t;cin>>s>>t;
        if(!flag[t][s])cout<<-1<<'\n';
        else cout<<dist[t][s]<<'\n';
    }

    return 0;
}