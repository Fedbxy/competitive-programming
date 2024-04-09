#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(vector<int> &a, ll c, ll x) {
    ll sum = 0;
    for(auto e:a) {
        sum += pow(1LL * e + 2 * x, 2);
        if(sum > c) break;
    }
    return sum >= c;
}

void solve() {
    int n; ll c; cin >> n >> c;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    ll l = 1, r = 1e9;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(ok(a, c, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("i.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}