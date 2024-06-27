#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;++i) cin >> arr[i];

    vector<int> dp(n+1);
    for(int i=1;i<=n;++i) {
        dp[i] = dp[i-1] + max(arr[i] - arr[i-1], 0);
    }
    
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << dp[r] - dp[l] << '\n';
    }
    return 0;
}