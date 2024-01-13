// written by poom
// score: 5/5

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll a[n+1], b[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    int k;
    cin >> k;

    ll dp[n+1][k+1];
    for (int i = 0; i <= k; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= a[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + b[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];
}