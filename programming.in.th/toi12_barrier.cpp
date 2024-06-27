#include <bits/stdc++.h>

#define int long long

using namespace std;
using pii = pair<int, int>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, w; cin >> n >> w;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    vector<int> qs(n+1);
    for(int i=1;i<=n;++i) qs[i] = qs[i-1] + a[i-1];

    int ans = 0, answ = 0;
    deque<pii> dq;
    dq.push_back({0, 0});
    for(int i=1;i<=n;++i) {
        while(!dq.empty() and dq.front().second < i - w) dq.pop_front();
        while(!dq.empty() and dq.back().first >= qs[i]) dq.pop_back();
        dq.push_back({qs[i], i});
        int res = qs[i] - dq.front().first;
        if(res > ans) {
            ans = res;
            answ = i - dq.front().second;
        } else if(res == ans) {
            answ = min(answ, i - dq.front().second);
        }
    }
    cout << ans << '\n';
    cout << answ << '\n';
    return 0;
}