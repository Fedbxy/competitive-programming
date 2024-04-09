#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if((b % 3) + c < 3 and b % 3 != 0) {
        cout << -1 << '\n';
        return;
    }
    int ans = a;
    ans += b / 3;
    b %= 3;
    int r = b + c;
    ans += r / 3;
    r %= 3;
    if(r) ans++;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("i.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}