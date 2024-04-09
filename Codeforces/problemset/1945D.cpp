#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n+1), b(n+1), mn(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) mn[i] = min(a[i], b[i]);

    ll sum = 0, ans = LLONG_MAX;
    for(int i=n;i>m;i--) sum += mn[i];
    for(int i=m;i>0;i--) {
        ans = min(ans, sum + a[i]);
        sum += min(a[i], b[i]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("i.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}