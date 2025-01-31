#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& e: a) cin >> e;

    for (int i = 1; i < n; ++i) a[i] += a[i - 1];

    while (q--) {
        int x; cin >> x;
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << (idx == n ? -1 : idx + 1) << '\n';
    }
    return 0;
}