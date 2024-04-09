#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int v, ans = 0;
    for(int i=0;i<n;i++) cin >> v, ans += abs(v);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}