#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> state(n), w(n);
    for(auto &e: state) cin >> e;
    for(auto &e: w) cin >> e;

    int ans = 0;
    for(int i=n-1;i>=0;--i) {
        if(state[i]) {
            ans += (1LL << i);
        } else if(k >= w[i]) {
            ans += (1LL << i);
            k -= w[i];
        }
    }
    cout << ans << '\n';
    return 0;
}