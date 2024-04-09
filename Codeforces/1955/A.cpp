#include <bits/stdc++.h>

using namespace std;

int n, a, b;

void solve() {
    cin >> n >> a >> b;
    cout << min(a * n, (n >> 1) * b + (n % 2) * a) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}