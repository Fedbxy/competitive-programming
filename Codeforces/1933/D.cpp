#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    bool ans = false;

    sort(a.begin(), a.end());
    if(a[0] != a[1]) ans = true;
    for(int i=1;i<n;i++) if(a[i] % a[0]) ans = true;
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}