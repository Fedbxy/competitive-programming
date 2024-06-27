#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n+1), bits(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        int sum = 0;
        for(int j=0;j<m;++j) {
            int x; cin >> x;
            sum += x << j;
        }
        bits[i] = sum;
    }

    vector<ll> dp(1<<m);
    dp[0] = 0;
    for(int i=1;i<1<<m;++i) dp[i] = 1e18;
    for(int i=1;i<=n;++i) {
        for(int mask=0;mask<1<<m;++mask) {
            dp[bits[i]|mask] = min(dp[bits[i]|mask], dp[mask] + a[i]);
        }
    }

    cout << dp[(1<<m)-1] << '\n';
    return 0;
}