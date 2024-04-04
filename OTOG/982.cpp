#include <bits/stdc++.h>

#define int long long
#define INT_MAX LLONG_MAX

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;
int parent[N], sz[N];
int minDiff = INT_MAX, ans, ans1, ans2;

struct Edge {
    int u, v, w;
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

int dfs(vector<pii> *adj, int u, int p) {
    int sum = 0;
    for(auto [v, w]: adj[u]) {
        if(v == p) continue;
        int sumDown = dfs(adj, v, u);
        int sumUp = ans - sumDown - w;
        if(minDiff > abs(sumDown - sumUp)) {
            minDiff = abs(sumDown - sumUp);
            ans1 = min(sumDown, sumUp);
            ans2 = max(sumDown, sumUp);
            // cout << minDiff << ": " << ans1 << ' ' << ans2 << '\n';
        }
        sum += sumDown + w;
    }
    return sum;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<N;i++) parent[i] = i, sz[i] = 1;
    int n, m; cin >> n >> m;
    vector<Edge> edge;
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    sort(edge.begin(), edge.end(), cmp);
    vector<pii> mst[n];
    for(int i=0;i<m;i++) {
        if(findSet(edge[i].u) != findSet(edge[i].v)) {
            ans += edge[i].w;
            mst[edge[i].u].emplace_back(edge[i].v, edge[i].w);
            mst[edge[i].v].emplace_back(edge[i].u, edge[i].w);
            unionSet(edge[i].u, edge[i].v);
        }
    }

    dfs(mst, 0, -1);
    cout << ans << '\n';
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}