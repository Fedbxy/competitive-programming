#include <bits/stdc++.h>
 
using namespace std;
const int md = 1e9 + 7;
using ll = long long;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    ll sum = 0, mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum = max(sum + a[i], (ll)a[i]);
        mx = max(mx, sum);
    }
 
    mx = max(mx, 0LL);
 
    ll ans = 0, cnt = 0, temp = mx;
    for(auto e : a) ans += e;

    for(int i = 0; i < k; i++) {
        mx = (mx * 2) % md;
    }
 

    cout << ((ans + mx - temp) % md + md) % md << '\n';
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}