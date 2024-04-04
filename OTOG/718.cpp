#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    int dp[n+1][m+1];
    for(int i=0;i<=m;i++) dp[0][i] = 0;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            dp[i][j] = a[i];
            if(j >= 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]);
            if(i >= 2) dp[i][j] = max(dp[i][j], dp[i-2][j] + a[i]);
            if(i >= 3) dp[i][j] = max(dp[i][j], dp[i-3][j] + a[i]);
        }
    }

    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=m;j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = INT_MIN;
    for(int i=0;i<=n;i++) ans = max(ans, dp[i][m]);
    cout << ans << '\n';
    return 0;
}

/*
dp[i][j] = max cheese at idx i with j potion left

base case:
dp[0][j] = 0; no cheese

recurence relation:
dp[i][j] = a[i] + max(dp[i-1][j-1], dp[i-2][j], dp[i-3][j]);
                       use potion     skip    skip from before

ans:
max(dp[i][m]) for all possible pos
*/