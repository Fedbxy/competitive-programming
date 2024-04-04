#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

void solve() {
    int n; cin >> n;
    vector<int> ans;
    for(int i=1;i<n;i++) if(gcd(i, n) == 1) ans.push_back(i);
    cout << ans.size() << '\n';
    for(auto e:ans) cout << e << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}