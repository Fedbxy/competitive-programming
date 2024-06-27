#include <bits/stdc++.h>

#define int long long

using namespace std;
using pii = pair<int, int>;

const int N = 2e5 + 10;
int parent[N], sz[N];

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return this->w > other.w;
    }
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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<N;++i) parent[i] = i, sz[i] = 1;

    int n, m; cin >> n >> m;
    vector<Edge> edge;
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end());

    int ans = 0;
    for(int i=0;i<m;++i) {
        Edge now = edge[i];
        if(findSet(now.u) != findSet(now.v)) {
            unionSet(now.u, now.v);
            ans += now.w;
        }
    }
    cout << ans - n + 1 << '\n';
    return 0;
}