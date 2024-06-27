#include <bits/stdc++.h>

#define int long long

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;
int parent[N], sz[N];
set<int> st[N], com;
int ans[N];

int findSet(int u) {
    if(u == parent[u]) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v, int a) {
    int U = findSet(u), V = findSet(v);
    if(U == V) {
        st[U].insert(a);
        return;
    };
    if(sz[U] >= sz[V]) {
        com.insert(u);
        com.erase(v);
        parent[V] = U;
        sz[U] += sz[V];
        sz[V] = 0;
        for(auto e: st[V]) {
            st[U].insert(e);
        }
        st[V].clear();
        st[U].insert(a);
    } else {
        com.insert(v);
        com.erase(u);
        parent[U] = V;
        sz[V] += sz[U];
        sz[U] = 0;
        for(auto e: st[U]) {
            st[V].insert(e);
        }
        st[U].clear();
        st[V].insert(a);
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, q; cin >> n >> m >> q;
    for(int i=0;i<n;++i) parent[i] = i, sz[i] = 1, com.insert(i);
    for(int i=0;i<m;++i) {
        int u, v, a; cin >> u >> v >> a;
        unionSet(u, v, a);
    }

    for(auto p: com) for(auto i: st[p]) ans[p] += (1LL << i);

    while(q--) {
        int s, t; cin >> s >> t;
        if(findSet(s) != findSet(t)) {
            cout << -1 << '\n';
            continue;
        }

        cout << ans[findSet(s)] << '\n';
    }

    return 0;
}

/*
11 10 5
1 3 2
1 2 1
2 3 1
3 2 0
8 9 4
4 5 4
5 6 0
4 6 3
5 7 4
0 6 0
*/