#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(ll n, ll x) {
    return (x / 7) * 23 + ((x / 7) / 12) * 98 >= n;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n; cin >> n;
    ll l = 0, r = 1e18;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(ok(n, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}