#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n-1);
    for(auto &e: a) cin >> e;

    vector<int> ans;
    ans.push_back(a[0]+1);
    for(int i=0;i<a.size()-1;++i) {
        if(a[i] > a[i+1]) {
            ans.push_back(a[i]);
        } else {
            int val = a[i+1] / ans.back() * ans.back() + a[i];
            if(val > a[i+1]) ans.push_back(val);
            else ans.push_back((a[i+1] / ans.back() + 1) * ans.back() + a[i]);
        }
    }
    ans.push_back(a.back());

    for(auto e: ans) cout << e << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}