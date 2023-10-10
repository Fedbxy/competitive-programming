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
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) parent[i]=i,sz[i]=1;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
    }
    stack<string> stack_cmd;
    stack<int> stack_u;
    stack<int> stack_v;
    while(k--){
        string cmd;cin>>cmd;
        int u,v;cin>>u>>v;
        stack_cmd.push(cmd);
        stack_u.push(u);
        stack_v.push(v);
    }
    stack<bool> stack_ans;
    while(!stack_cmd.empty()){
        string cmd=stack_cmd.top();stack_cmd.pop();
        int u=stack_u.top();stack_u.pop();
        int v=stack_v.top();stack_v.pop();
        if(cmd=="ask"){
            stack_ans.push(findSet(u)==findSet(v));
        }else{
            unionSet(u,v);
        }
    }
    while(!stack_ans.empty()){
        bool ans=stack_ans.top();stack_ans.pop();
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}