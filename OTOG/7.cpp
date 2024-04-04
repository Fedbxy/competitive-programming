#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int dp[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    
    for(int i=0;i<=m;i++) dp[1][i] = a[1][i];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j] = dp[i-1][j] + a[i][j];
            if(j - 1 > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i][j]);
            if(j + 1 <= m) dp[i][j] = min(dp[i][j], dp[i-1][j+1] + a[i][j]);
        }
    }

    int ans = INT_MAX;
    for(int i=1;i<=m;i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
    return 0;
}