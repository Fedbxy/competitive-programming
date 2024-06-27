#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    vector<int> dp(n), mn(n+1);
    int len = 1;
    dp[0] = 1;
    mn[1] = a[0];
    for(int i=1;i<n;++i) {
        if(a[i] >= mn[len]) {
            dp[i] = ++len;
            mn[len] = a[i];
        } else {
            int idx = upper_bound(mn.begin() + 1, mn.begin() + len + 1, a[i]) - mn.begin();
            dp[i] = idx;
            mn[idx] = a[i];
        }
    }
    
    int ans = 0;
    for(auto e: dp) ans = max(ans, e);
    cout << n - ans << '\n';
    return 0;
}