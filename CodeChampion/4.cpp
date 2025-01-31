#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &e: a) cin >> e;
    for (auto &e: b) cin >> e;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += (a[i] * b[i]);

    cout << sum << '\n';
    return 0;
}