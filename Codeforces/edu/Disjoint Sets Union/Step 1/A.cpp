#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int parent[N], sz[N];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    int U = findSet(u);
    int V = findSet(v);
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
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i] = i, sz[i] = 1;
    while(m--) {
        string cmd;cin>>cmd;
        if(cmd == "union") {
            int u,v;cin>>u>>v;
            unionSet(u,v);
        } else {
            int u,v;cin>>u>>v;
            cout<<(findSet(u) == findSet(v) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}