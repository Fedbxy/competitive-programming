#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto e: a) pq.push(e);

    int ans = 0;
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if(pq.size() + 1 > q) ans += a * b;
        pq.push(a + b);
    }
    cout << ans << '\n';
    return 0;
}