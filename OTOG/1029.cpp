#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &e: a) cin >> e;
    for (auto &e: b) cin >> e;

    vector<int> ans(n);
    vector<bool> used(n);
    int i = 0, x = 0, y = n - 1;
    while (i < n) {
        if (!used[a[i]]) ans[x++] = a[i], used[a[i]] = true;
        if (!used[b[i]]) ans[y--] = b[i], used[b[i]] = true;
        ++i;
    }

    for (auto &e: ans) cout << e << '\n';
    return 0;
}