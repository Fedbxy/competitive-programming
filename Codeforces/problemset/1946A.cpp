#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int prev, idx = (n+1) / 2, ans = 0;
    while(idx <= n) {
        if(ans == 0) prev = a[idx], ans++, idx++;
        if(a[idx] != prev) break;
        prev = a[idx];
        ans++;
        idx++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}