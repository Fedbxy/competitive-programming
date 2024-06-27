#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    if(n >= 4) cout << n / 4 + (n % 4) / 2 << '\n';
    else cout << n / 2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}