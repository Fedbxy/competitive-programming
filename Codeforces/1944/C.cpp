#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    map<int, int> m;
    for(int e:a) m[e]++;

    int ans = INT_MAX;
    for(int i=0;i<2e5;i++) if(m.find(i) == m.end()) {
        ans = i;
        break;
    }

    bool isTurn = true;
    for(int i=0;i<ans;i++) {
        if(m[i] == 1) {
            if(isTurn) isTurn = false;
            else {
                ans = i;
                break;
            }
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