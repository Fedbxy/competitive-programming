#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    if(a > c) swap(a, c), swap(b, d);
    cout << (a < c and b < d and b > c ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}