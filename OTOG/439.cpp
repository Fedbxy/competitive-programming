#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];
    reverse(a.begin(), a.end());
    
    vector<int> dp(n);
    for(int i=1;i<n;i++) {
        if(i - a[i] >= 0) dp[i] = min(dp[i - a[i]], dp[i - 1]) + 1;
        else dp[i] = dp[i-1] + 1;
    }
    cout << dp[n-1] << '\n';
    return 0;
}