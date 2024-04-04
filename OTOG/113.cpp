#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int> dp(n+1);
    for(int i=1;i<=min(2, n);i++) dp[i] = 0;
    for(int i=3;i<=min(5, n);i++) dp[i] = max(a[i], dp[i-1]);
    if(n >= 6) dp[6] = max(a[6] + dp[3], dp[5]);
    for(int i=7;i<=n;i++) dp[i] = max(a[i] + max(dp[i-3], dp[i-4]), dp[i-1]);
    int ans = 0;
    for(auto e:dp) ans = max(ans, e);
    cout << ans << '\n';
    return 0;
}

/*
12
1 2 5 4 3 0 6 183276 2 7 2 1
*/