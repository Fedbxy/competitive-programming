#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    map<int, int> b;
    for(auto &e: a) cin >> e;
    for(int i = 0; i < m; ++i) {
        int x; cin >> x;
        ++b[x];
    }

    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        int x = a[i];
        if(b.find(x) != b.end() and b[x]-- > 0) ++cnt;
    }

    int ans = (cnt >= k ? 1 : 0);
    for(int i = 1; i < n - m + 1; ++i) {
        int prev = a[i - 1], next = a[i + m - 1];
        if(b.find(prev) != b.end() and b[prev]++ >= 0) --cnt;
        if(b.find(next) != b.end() and b[next]-- > 0) ++cnt;
        if(cnt >= k) ++ans;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}