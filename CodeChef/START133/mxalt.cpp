#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    sort(a.begin(), a.end(), greater<int>());

    int ans = (n % 2 ? a[n/2] : 0);
    int i = 0, j = n-1;
    while(i < j) ans += a[i++] - a[j--];
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}