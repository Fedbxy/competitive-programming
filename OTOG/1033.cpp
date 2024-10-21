#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(n);
    for (auto &e: a) cin >> e;

    for (int i = 0; i < n; ++i) b[i] = (i > 0 ? a[i - 1] : 0) + a[i] + (i < n - 1 ? a[i + 1] : 0);
    sort(b.begin(), b.end());

    while (q--) {
        ll l, r; cin >> l >> r;
        int i = lower_bound(b.begin(), b.end(), l) - b.begin();
        int j = upper_bound(b.begin(), b.end(), r) - b.begin() - 1;
        cout << j - i + 1 << '\n';
    }
    return 0;
}