#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, w;
};

bool cmp(const edge &l, const edge &r) {
    return l.w > r.w;
}

const int N = 1e5 + 10;
int parent[N], sz[N];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    int U = findSet(u), V = findSet(v);
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
    int n, m, k; cin >> n >> m >> k;
    vector<edge> a;
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        a.push_back({u, v, w});
    }
    for(int i=1;i<=n;i++) parent[i] = i, sz[i] = 1;
    sort(a.begin(), a.end(), cmp);

    int ans = INT_MAX;
    int cnt = n;
    for(int i=0;i<m;i++) {
        if(cnt == k) break;
        if(findSet(a[i].u) != findSet(a[i].v)) {
            ans = min(ans, a[i].w);
            unionSet(a[i].u, a[i].v);
            cnt--;
        }
    }

    cout << ans << '\n';
    return 0;
}