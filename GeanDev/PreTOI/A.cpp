#include <bits/stdc++.h>

using namespace std;
#define int long long
using pii = pair<int, int>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &e: a) cin >> e;
    for(auto &e: b) cin >> e;

    vector<int> sol = {0};
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0;i<n;++i) pq.emplace(a[i], b[i]);
    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        sol.push_back(sol.back() + now.first);
        if(now.second != -1) pq.emplace(now.second, -1);
    }

    // for(int i=0;i<sol.size();++i) cout << sol[i] << ' ' << i << '\n';

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        int idx = upper_bound(sol.begin(), sol.end(), x) - sol.begin();
        cout << idx - 1 << '\n';
    }
    return 0;
}