#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll md = 1e9 + 7;

void solve() {
    ll x; cin >> x;
    if(x == 2 or x == 1) cout << "NO\n";
    else cout << (x % md) - 3 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}