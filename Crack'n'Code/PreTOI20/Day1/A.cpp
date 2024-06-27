#include <bits/stdc++.h>

using namespace std;

const int M = 705, N = 1005;
int n, m, k;
vector<int> adj[M][N];
bool flag[M][N];
int dp[M][M];

int dfs(int g, int u) {
    flag[g][u] = true;

    int res = 1;
    for(auto v: adj[g][u]) {
        if(flag[g][v]) continue;
        res += dfs(g, v);
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=1;i<=m;++i) {
        int nEdge; cin >> nEdge;
        for(int j=0;j<nEdge;++j) {
            int u, v; cin >> u >> v;
            adj[i][u].push_back(v);
            adj[i][v].push_back(u);
        }
    }

    vector<int> cnt(m+1);
    for(int i=1;i<=m;++i) {
        for(int u=1;u<=n;++u) {
            if(flag[i][u]) continue;
            cnt[i] = max(cnt[i], dfs(i, u));
        }
    }

    // sort(cnt.begin() + 2, cnt.end(), greater<int>());
    // int ans = cnt[1];
    // for(int i=2;i<=k+1;++i) {
    //     ans += cnt[i];
    // }
    // cout << ans << '\n';

    for(int i=0;i<=k;++i) dp[1][i] = cnt[1];
    for(int i=2;i<=m;++i) {
        for(int j=0;j<=k;++j) {
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + cnt[i]);
        }
    }
    // for(int i=1;i<=m;++i) {
    //     for(int j=0;j<=k;++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][k] << '\n';
    return 0;
}