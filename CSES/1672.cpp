#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    ll dist[n+1][n+1];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j] = (i == j ? 0 : LLONG_MAX);
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], 1LL * w);
        dist[v][u] = min(dist[v][u], 1LL * w);
    }

    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dist[i][k] != LLONG_MAX and dist[k][j] != LLONG_MAX) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    while(q--) {
        int u, v; cin >> u >> v;
        ll ans = dist[u][v];
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }
    return 0;
}