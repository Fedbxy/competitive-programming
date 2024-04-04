#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    int cnt = 0;
    while(a - b < 10) a += 3, cnt++;
    cout << cnt << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}