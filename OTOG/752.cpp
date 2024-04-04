#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> dp(n+1);
    for(int i=1;i<=n;i++) dp[i] = a[i-1] + dp[i-1];

    vector<pair<int, int>> idx(n);
    for(int i=0;i<n;i++) idx[i].first = dp[i+1], idx[i].second = i;
    sort(idx.begin(), idx.end());

    int mn = INT_MAX;
    for(int i=n-1;i>=0;i--) mn = min(mn, idx[i].second), idx[i].second = mn;

    while(q--) {
        int x; cin >> x;
        int pos = lower_bound(idx.begin(), idx.end(), make_pair(x, INT_MIN)) - idx.begin();
        cout << (pos == n ? -1 : idx[pos].second) << '\n';
    }
    return 0;   
}