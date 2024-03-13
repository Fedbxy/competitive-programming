#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> dp(n), mn(n+1);
    dp[0] = 1, mn[1] = a[0];
    int len = 1;
    for(int i=1;i<n;i++) {
        if(a[i] > mn[len]) {
            len++;
            dp[i] = len;
            mn[len] = a[i];
        } else {
            int p = lower_bound(mn.begin()+1, mn.begin()+len+1, a[i]) - mn.begin();
            dp[i] = p;
            mn[p] = a[i]; 
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}