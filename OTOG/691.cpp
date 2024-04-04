#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> parent, sz;

struct Edge {
    int u, v, w, r;
};

bool cmp(const Edge &l, const Edge &r) {
    return l.w < r.w;
}

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
    int n, m; cin >> n >> m;
    parent.resize(n); sz.resize(n);
    for(int i=0;i<n;i++) parent[i] = i, sz[i] = 1;
    vector<Edge> edge;
    for(int i=0;i<m;i++) {
        int u, v, w, r; cin >> u >> v >> w >> r;
        edge.push_back({u, v, w, r});
        if(r) unionSet(u, v);
    }

    int p; cin >> p;
    vector<pii> c(p);
    for(int i=0;i<p;i++) cin >> c[i].first >> c[i].second;
    sort(c.begin(), c.end());
    int prev = c[p-1].second;
    for(int i=p-2;i>=0;i--) {
        if(prev < c[i].second) c[i].second = prev;
        prev = c[i].second;
    }
    for(int i=0;i<m;i++) edge[i].w = (*lower_bound(c.begin(), c.end(), make_pair(edge[i].w, INT_MIN))).second;
    sort(edge.begin(), edge.end(), cmp);
    
    ll ans = 0;
    for(int i=0;i<m;i++) {
        if(findSet(edge[i].u) != findSet(edge[i].v)) {
            ans += 1LL * edge[i].w;
            unionSet(edge[i].u, edge[i].v);
        }
    }
    cout << ans << '\n';
    return 0;
}