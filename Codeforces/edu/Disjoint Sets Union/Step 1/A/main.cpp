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
    int p_u=findSet(u);
    int p_v=findSet(v);
    if(sz[p_u]>=sz[p_v]){
        parent[p_v]=p_u;
        sz[p_u]+=sz[p_v];
        sz[p_v]=0;
    }else{
        parent[p_u]=p_v;
        sz[p_v]+=sz[p_u];
        sz[p_u]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i,sz[i]=1;
    while(m--){
        string cmd;cin>>cmd;
        if(cmd=="union"){
            int u,v;cin>>u>>v;
            unionSet(u,v);
        }else{
            int u,v;cin>>u>>v;
            if(findSet(u)==findSet(v)) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}