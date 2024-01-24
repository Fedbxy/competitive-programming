// kruskal
/*
#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u,v,w;
};

bool cmp(const edge &l, const edge &r) {
    return l.w < r.w;
}

const int N = 5e5 + 10;

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
    int ans = 0;
    for(int i=0;i<m;i++) {
        if(findSet(a[i].u) != findSet(a[i].v)) {
            ans += a[i].w;
            unionSet(a[i].u, a[i].v);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
*/

// prim

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<pii> adj[n];
    vector<int> dist(n, INT_MAX);
    vector<bool> flag(n);
    int start = -1;
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        if(start == -1) start = u;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});
    ll ans = 0;
    while(!pq.empty()) {
        int W = pq.top().first, u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;
        ans += W;

        for(auto vw:adj[u]) {
            int v = vw.first, w = vw.second;
            if(dist[v] > w) {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}