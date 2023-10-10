#include <bits/stdc++.h>

using namespace std;

struct edge1{
    int u,v,w;
};

const int N=2e5+1;
// const int M=1e6+1;
vector<edge1> edge;
int parent[N];

int findSet(int u){
    if(parent[u]==u) return u;
    return parent[u]=findSet(parent[u]);
}

void unionSet(int u,int v){
    int U=findSet(u);
    int V=findSet(v);
    parent[V]=U;
}

bool cmp(const edge1 &l,const edge1 &r){
    return l.w>r.w;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    long long int ans=0;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    sort(edge.begin(),edge.end(),cmp);
    for(int i=0;i<m;i++){
        if(findSet(edge[i].u)!=findSet(edge[i].v)){
            unionSet(edge[i].u,edge[i].v);
            ans+=(edge[i].w-1);
        }
    }
    cout<<ans<<'\n';
    return 0;
}