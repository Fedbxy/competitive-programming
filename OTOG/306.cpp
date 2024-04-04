#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), dp(n); for(int i=0;i<n;i++) cin >> a[i];
    dp[0] = a[0];
    for(int i=1;i<n;i++) dp[i] = max((i - 2 >= 0 ? dp[i-2] + a[i] : a[i]), dp[i-1]);
    cout << dp[n-1] << '\n';
    return 0;
}