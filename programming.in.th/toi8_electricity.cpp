#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 5e5 + 10;
int a[N], dp[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    for(int i=1;i<=n;++i) cin >> a[i];

    // dp[1] = a[1];
    // for(int i=2;i<=n;++i) {
    //     dp[i] = INT_MAX;
    //     for(int j=max(i-k, 1);j<i;++j) {
    //         dp[i] = min(dp[i], dp[j] + a[i]);
    //     }
    // }

    // cout << dp[n] << '\n';

    dp[1] = a[1];
    deque<pii> dq;
    dq.push_back({a[1], 1});
    for(int i=2;i<=n;++i) {
        while(!dq.empty() and dq.front().second < i - k) dq.pop_front();
        while(!dq.empty() and dq.back().first >= a[i] + dq.front().first) dq.pop_back();
        dp[i] = a[i] + dq.front().first;
        dq.push_back({dp[i], i});
    }

    cout << dp[n] << '\n';

    return 0;
}