#include <bits/stdc++.h>

using namespace std;

const int N=1e5+1;
int parent[N];
int sz[N];

int findSet(int u){
    if(parent[u]==u) return u;
    return parent[u]=findSet(parent[u]);
}

void unionSet(int u,int v){
    int U=findSet(u);
    int V=findSet(v);
    if(U==V) return;
    if(sz[U]>=sz[V]){
        parent[V]=U;
        sz[U]+=sz[V];
        sz[V]=0;
    }else{
        parent[U]=V;
        sz[V]+=sz[U];
        sz[U]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i,sz[i]=1;
    while(m--){
        string cmd;cin>>cmd;
        if(cmd=="join"){
            int u,v;cin>>u>>v;
            unionSet(u,v);
        }else if(cmd=="add"){
            
        }else{
            int u,v;cin>>u>>v;
            if(findSet(u)==findSet(v)) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}