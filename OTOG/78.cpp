#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1e2 + 10;
vector<pii> adj[N];
int flag[N];
bool isCycle;

void dfs(int u, int prev) {
    if(flag[u] == 1) {
        isCycle = true;
        return;
    }

    flag[u] = 1;
    for(auto [v, w]: adj[u]) {
        if(flag[v] != 2 and v != prev) dfs(v, u);
    }
    flag[u] = 2;
}

int recur(int u, int prev) {
    int mx = 0;
    for(auto [v, w]: adj[u]) {
        if(v == prev) continue;
        mx = max(mx, recur(v, u) + w);
    }
    return mx;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, s; cin >> n >> m >> s;
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for(int i=1;i<=n;++i) {
        if(!flag[i]) dfs(i, -1);
    }
    
    if(isCycle or m >= n) {
        cout << "YES\n";
        return 0;
    }

    int mx = 0;
    for(int i=1;i<=n;++i) {
        if(adj[i].size() == 1) mx = max(mx, recur(i, -1));
    }

    cout << (mx >= s ? "YES" : "NO") << '\n';

    return 0;
}

/*
8 8 1000000
2 1 3
2 3 2
3 4 2000
3 5 10
5 6 1000
7 5 1
8 7 3000
*/