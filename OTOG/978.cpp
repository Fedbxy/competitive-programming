#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0;i<n;i++) {
        ll x, y; cin >> x >> y;
        pq.emplace(x, y);
    }

    ll ans = 0;
    while(!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();
        // cout << x << ' ' << y << '\n';
        while(!pq.empty() and pq.top().first == x) {
            y += pq.top().second;
            pq.pop();
        }
        if(y % 2) ans++;
        if(y >= 2) pq.emplace(2 * x, y / 2);
    }
    // for(auto e: ans) cout <<e << ' ';
    // cout << '\n';
    cout << ans << '\n';
    return 0;
}