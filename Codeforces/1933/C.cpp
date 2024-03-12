#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, l; cin >> a >> b >> l;
    unordered_set<int> ans;
    for(int i=0;i<=50;i++) {
        for(int j=0;j<=50;j++) {
            double k = l / (pow(a, i) * pow(b, j));
            if(k == floor(k)) ans.insert(k); // cout << k << " * " << a << "^" << i << " * " << b << "^" << j << " = " << k * pow(a, i) * pow(b, j) << '\n';
        }
    }
    for(auto e:ans) if(e == 0) ans.erase(e);
    cout << ans.size() << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}