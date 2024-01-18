#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int parent[N], sz[N], mx[N], mn[N];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    int U = findSet(u);
    int V = findSet(v);
    if(U == V) return;
    if(sz[U] >= sz[V]) {
        parent[V] = U;
        sz[U] += sz[V];
        sz[V] = 0;
        mx[U] = max(mx[U], mx[V]);
        mn[U] = min(mn[U], mn[V]);
    } else {
        parent[U] = V;
        sz[V] += sz[U];
        sz[U] = 0;
        mx[V] = max(mx[U], mx[V]);
        mn[V] = min(mn[U], mn[V]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i] = i, sz[i] = 1, mx[i] = i, mn[i] = i;
    while(m--) {
        string cmd;cin>>cmd;
        if(cmd == "union") {
            int u,v;cin>>u>>v;
            unionSet(u,v);
        } else {
            int u;cin>>u;
            int p = findSet(u);
            cout<<mn[p]<<' '<<mx[p]<<' '<<sz[p]<<'\n';
        }
    }
    return 0;
}