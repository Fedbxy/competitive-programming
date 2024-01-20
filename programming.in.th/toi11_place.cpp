#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
    int u,v,w;
};

bool cmp(const edge &l, const edge &r) {
    return l.w > r.w;
}

const int N = 2e5 + 10;
vector<edge> a;
int parent[N], sz[N];

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
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) parent[i] = i, sz[i] = 1;
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        a.push_back({u,v,w});
    }
    sort(a.begin(), a.end(), cmp);
    ll ans = 0;
    for(int i=0;i<m;i++) {
        if(findSet(a[i].u) != findSet(a[i].v)) {
            ans += a[i].w - 1;
            unionSet(a[i].u, a[i].v);
        }
    }
    cout<<ans<<'\n';
    return 0;
}