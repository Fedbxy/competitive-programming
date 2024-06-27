#include <bits/stdc++.h>

using namespace std;

int _gcd(int a, int b) {
    return b == 0 ? a : _gcd(b, a % b);
}

void solve() {
    int x; cin >> x;
    
    int mx = 0, ans;
    for(int y=1;y<x;++y) {
        int gcd = _gcd(x, y);
        if(gcd + y > mx) {
            mx = gcd + y;
            ans = y;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}