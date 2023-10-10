#include <bits/stdc++.h>

using namespace std;

struct edge1{
    int u,v,w;
    int idx;
};

const int N=1e5+10;
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
    if(m<n){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        edge.push_back({u,v,w,i+1});
    }
    int t;cin>>t;
    sort(edge.begin(),edge.end(),cmp);
    long long int ans=0;
    vector<int> idx;
    bool found=false;
    for(int i=0;i<m;i++){
        if(findSet(edge[i].u)!=findSet(edge[i].v)){
            unionSet(edge[i].u,edge[i].v);
            ans+=edge[i].w;
            idx.push_back(edge[i].idx);
        }else if(!found) ans+=edge[i].w,idx.push_back(edge[i].idx),found=true;
    }
    set<int> parentList;
    for(int i=1;i<=n;i++){
        parentList.insert(findSet(i));
    }
    sort(idx.begin(),idx.end());
    if(parentList.size()!=1){
        cout<<-1<<'\n';
        return 0;
    }
    cout<<ans<<'\n';
    if(t==2){
        for(int e:idx){
            cout<<e<<" ";
        }
        cout<<'\n';
    }
    return 0;
}