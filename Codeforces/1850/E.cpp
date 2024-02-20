#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(vector<int> &a, ll c, ll x) {
    ll sum = 0;
    for(auto e:a) {
        sum += (2 * x + e) * (2 * x + e);
        if(sum > c) break;
    }
    // cout << " = " << sum;
    return sum >= c;
}

void solve() {
    int n; cin >> n;
    ll c; cin >> c;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll l = 1, r = 1e9;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        // cout << "#" << mid;
        if(ok(a, c, mid)) {
            // cout << " true";
            r = mid;
        } else l = mid + 1;
        // cout << '\n';
    }
    cout << r << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}