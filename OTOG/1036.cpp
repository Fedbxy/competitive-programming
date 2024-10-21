#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (auto &e: a) cin >> e;

    vector<ll> ps(n+1);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i - 1] * (i % 2 ? 1 : -1);

    while (q--) {
        int l, r; cin >> l >> r;
        cout << (ps[r] - ps[l - 1]) * (l % 2 ? 1 : -1) << '\n';
    }
    return 0;
}