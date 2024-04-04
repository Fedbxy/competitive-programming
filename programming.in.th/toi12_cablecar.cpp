#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> parent, sz;

struct Edge {
    int u, v;
    ll w;
};

bool cmp(const Edge &l, const Edge &r) {
    return l.w > r.w;
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
        sz[U] += sz[V]; sz[V] = 0;
    } else {
        parent[U] = V;
        sz[V] += sz[U]; sz[U] = 0;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    parent.resize(n+1), sz.resize(n+1);
    for(int i=1;i<=n;i++) parent[i] = i, sz[i] = 1;
    vector<Edge> edge;
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    int s, t, p; cin >> s >> t >> p;
    ll ans = INT_MAX;
    sort(edge.begin(), edge.end(), cmp);
    for(int i=0;i<m;i++) {
        if(findSet(edge[i].u) != findSet(edge[i].v)) {
            ans = min(ans, edge[i].w);
            unionSet(edge[i].u, edge[i].v);
            if(findSet(s) == findSet(t)) {
                cout << ceil(1.0 * p / (ans - 1)) << '\n';
                return 0;
            }
        }
    }
    return 0;
}