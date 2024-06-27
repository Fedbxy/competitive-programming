#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> w(n), v(n);
    for(int i=0;i<n;++i) cin >> w[i] >> v[i];

    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i=0;i<=n;++i) dp[i][0] = 0;
    for(int i=0;i<=m;++i) dp[0][i] = 0;
    for(int i=1;i<=n;++i) {
        for(int j=0;j<=m;++j) {
            dp[i][j] = dp[i-1][j];
            if(j >= w[i-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
            if(j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}