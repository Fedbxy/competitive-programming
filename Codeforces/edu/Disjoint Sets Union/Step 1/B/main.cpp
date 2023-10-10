#include <bits/stdc++.h>

using namespace std;

const int N=3e5+1;
int parent[N];
int sz[N];
int mn[N];
int mx[N];

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
        mn[U]=min(mn[U],mn[V]);
        mx[U]=max(mx[U],mx[V]);
    }else{
        parent[U]=V;
        sz[V]+=sz[U];
        mn[V]=min(mn[V],mn[U]);
        mx[V]=max(mx[V],mx[U]);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i,sz[i]=1,mn[i]=i,mx[i]=i;
    while(m--){
        string cmd;cin>>cmd;
        if(cmd=="union"){
            int u,v;cin>>u>>v;
            unionSet(u,v);
        }else{
            int u;cin>>u;
            int U=findSet(u);
            cout<<mn[U]<<" "<<mx[U]<<" "<<sz[U]<<'\n';
        }
    }
    return 0;
}