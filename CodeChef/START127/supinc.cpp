#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    cout << (k < 31 and pow(2, k-1) <= x ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}