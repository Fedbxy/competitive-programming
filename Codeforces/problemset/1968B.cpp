#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    vector<int> a0, a1;
    for(int i=0;i<m;++i) {
        if(b[i]-'0') a1.push_back(i);
        else a0.push_back(i);
    }

    int idx = -1, ans = 0;
    for(auto e: a) {
        int i;
        if(e - '0') {
            i = upper_bound(a1.begin(), a1.end(), idx) - a1.begin();
            if(i < a1.size()) {
                ++ans;
                idx = a1[i];
            } else break;
        } else {
            i = upper_bound(a0.begin(), a0.end(), idx) - a0.begin();
            if(i < a0.size()) {
                ++ans;
                idx = a0[i];
            } else break;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}