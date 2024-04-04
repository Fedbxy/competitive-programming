#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll a, b, m; cin >> a >> b >> m;
    ll ans = m / a + m / b + 2;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}