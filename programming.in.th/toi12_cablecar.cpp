#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pil = pair<int,ll>;

struct edge {
    int u,v;
    ll w;
};

bool cmp(const edge &l, const edge &r) {
    return l.w < r.w;
}

const int N = 3e3;
vector<edge> a;
vector<int> parent(N), sz(N);


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
    for(int i=1;i<=n;i++) parent[i] = i, sz[i] = 1;
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        a.push_back({u,v,w});
    }
    int s,d,p;cin>>s>>d>>p;
    for(int i=0;i<m;i++) a[i].w = ceil(1.0 * p / (a[i].w - 1));

    sort(a.begin(), a.end(), cmp);
    for(int i=0;i<m;i++) {
        if(findSet(a[i].u) != findSet(a[i].v)) {
            unionSet(a[i].u, a[i].v);
            if(findSet(s) == findSet(d)) {
                cout<<a[i].w<<'\n';
                return 0;
            }
        }
    }
    return 0;
}