#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    int mn = 0, mx = 0, hap = 0;
    while(n--) {
        int x; cin >> x;
        if(x >= l and x <= r) hap++;
        else hap--;
        mn = min(mn, hap);
        mx = max(mx, hap);
    }
    cout << mx << ' ' << mn << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}