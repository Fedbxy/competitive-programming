#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(a.begin(), a.end());

    ll op = 0;
    for(int i=0;i<n;i++) op += abs(i - a[i]);
    cout << op << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}