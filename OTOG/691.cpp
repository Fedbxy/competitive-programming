#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
    int u,v,w,flag;
};

bool cmp(const edge &l, const edge &r) {
    return l.w < r.w;
}

const int N = 3e3 + 10;
vector<edge> a;
int parent[N], sz[N];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    int U = findSet(u), V = findSet(v);
    if(U == V) return;
    if(sz[U] >= sz[V]) parent[V] = U, sz[U] += sz[V], sz[V] = 0;
    else parent[U] = V; sz[V] += sz[U], sz[U] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) parent[i] = i, sz[i] = 1;
    for(int i=0;i<m;i++) {
        int u,v,w,flag;cin>>u>>v>>w>>flag;
        a.push_back({u,v,w,flag});
        if(flag) unionSet(u,v);
    }

    int p;cin>>p;
    vector<pair<int,int>> b(p);
    for(int i=0;i<p;i++) cin>>b[i].first>>b[i].second;
    sort(b.begin(), b.end());
    for(int i=p-2;i>=0;i--) b[i].second = min(b[i].second, b[i+1].second);
    for(int i=0;i<m;i++) a[i].w = (*lower_bound(b.begin(), b.end(), make_pair(a[i].w, INT_MIN))).second;

    sort(a.begin(), a.end(), cmp);

    ll ans = 0;
    for(int i=0;i<m;i++) {
        if(findSet(a[i].u) != findSet(a[i].v)) {
            ans += a[i].w;
            unionSet(a[i].u, a[i].v);
        }
    }
    cout<<ans<<'\n';
    return 0;
}