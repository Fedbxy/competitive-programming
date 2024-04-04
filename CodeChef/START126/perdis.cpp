#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 0;
    for(int i=0;i<n-1;i++) if(a[i] == i + 1) swap(a[i], a[i+1]), ans++;
    if(a[n-1] == n) swap(a[n-1], a[n-2]), ans++;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}