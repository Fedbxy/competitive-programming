#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;
int parent[N], sz[N];

struct op {
    string cmd;
    int u,v;
};

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    int U = findSet(u), V = findSet(v);
    if(U == V) return;
    if(sz[U] >= sz[V]) {
        parent[V] = U;
        sz[U] += sz[V];
        sz[V] = 0;
    } else {
        parent[U] = V;
        sz[V] += sz[U];
        sz[U] = 0;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) parent[i] = i, sz[i] = 1;
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
    }
    stack<op> a;
    stack<bool> ans;
    while(k--) {
        string s;cin>>s;
        int u,v;cin>>u>>v;
        op temp;
        temp.cmd = s;temp.u = u;temp.v = v;
        a.push(temp);
    }
    while(!a.empty()) {
        string cmd = a.top().cmd;
        int u = a.top().u, v = a.top().v;
        a.pop();
        if(cmd == "cut") unionSet(u,v);
        else ans.push(findSet(u) == findSet(v));
    }
    while(!ans.empty()) cout<<(ans.top() ? "YES\n" : "NO\n"), ans.pop();
    return 0;
}