#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e2 + 10;
int a[N];
int dist[N][N], cnt[N][N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            dist[i][j] = a[i] + a[j];
            cnt[i][j] = 2;
        }
    }
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for(int k=1;k<=n;++k) {
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    cnt[i][j] = cnt[i][k] + cnt[k][j];
                } else if(dist[i][j] == dist[i][k] + dist[k][j]) {
                    cnt[i][j] = max(cnt[i][j], cnt[i][k] + cnt[k][j]);
                }
            }
        }
    }

    while(q--) {
        int l, r; cin >> l >> r;
        cout << dist[l][r] << ' ' << cnt[l][r] << '\n';
    }
    return 0;
}