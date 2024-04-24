#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=n;++i) cin >> b[i];

    int dp[n+1][n+1];
    for(int i=0;i<=n;++i) dp[i][0] = dp[0][i] = 0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}