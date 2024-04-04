#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n), c;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) if(b[i] - a[i] >= 0) c.push_back(b[i] - a[i]);

    reverse(c.begin(), c.end());

    n = c.size();
    if(!n) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> dp(n), mn(n+1);
    dp[0] = 1; mn[1] = c[0];
    int len = 1;
    for(int i=1;i<n;i++) {
        if(c[i] >= mn[len]) {
            len += 1;
            dp[i] = len;
            mn[len] = c[i];
        } else {
            int p = upper_bound(mn.begin() + 1, mn.begin() + len + 1, c[i]) - mn.begin();
            dp[i] = p;
            mn[p] = c[i];
        }
    }
    reverse(dp.begin(), dp.end());

    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}