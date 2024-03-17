#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=0;i<n+1;i++) cin >> a[i];

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int len=2;len<=n;len++) {
        for(int i=0;i<=n-len;i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i] * a[k+1] * a[j+1]);
            }
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}