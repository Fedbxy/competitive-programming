#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    if(n % 2 == 0) cout << (n / 2) * 13 << '\n';
    else cout << (n / 2) * 13 + 6 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}