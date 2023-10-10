#include <bits/stdc++.h>

using namespace std;

const int N=1e4+1;
vector<int> dist(N,-1);
vector<int> adj[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:adj[u]){
            if(dist[v]==-1) dist[v]=dist[u]+1,q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int k,n,m;cin>>k>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    bfs(1);
    for(int i=n;i>0;i--){
        if(dist[i]<=k and dist[i]!=-1){
            cout<<i<<"\n";
            return 0;
        }
    }
    return 0;
}