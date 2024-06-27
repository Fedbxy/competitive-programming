#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    cout << min(x, y) << ' ' << max(x, y) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}