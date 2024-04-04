#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        pq.push(x);
    }

    ll ans = 0;
    for(int i=0;i<k;i++) {
        ans += pq.top();
        ll val = pq.top() * 1.05;
        pq.pop();
        pq.push(val);
    }

    cout << ans << '\n';
    return 0;
}