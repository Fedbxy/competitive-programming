// written by poom
// score: 30/30

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll val[n + 1], qs[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        qs[i] = qs[i-1] + val[i];
    }

    deque<int> dq;
    ll dp[n + 1] = {};

    for (int i = x; i <= n; i++) {
        while (!dq.empty() && dq.front() + y < i) {
            dq.pop_front();
        }
        while (!dq.empty() && qs[dq.back()] > qs[i - x]) {
            dq.pop_back();
        }
        dq.push_back(i - x);
        dp[i] = qs[i] - qs[dq.front()];
    }

    ll total = -1e18;

    for (int i = x; i <= n; i++) {
        total = max(total, dp[i]);
    }

    cout << total;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int q;
    cin >> q;

    while (q--) {
        solve();
        cout << "\n";
    }
}

/*
10
3 1
10
4 1
5 0
3 1
3 0
5 1
2 1
10 0
7 0
9 1
2 0
*/