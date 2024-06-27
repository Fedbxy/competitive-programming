#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), h(n);
    for(auto &e: a) cin >> e;
    for(auto &e: h) cin >> e;

    vector<int> dp1(n), mn1(n+1);
    int len = 1;
    dp1[0] = 1;
    mn1[1] = h[0];
    for(int i=1;i<n;++i) {
        if(h[i] > mn1[len]) {
            dp1[i] = ++len;
            mn1[len] = h[i];
        } else {
            int idx = lower_bound(mn1.begin()+1, mn1.begin()+len+1, h[i]) - mn1.begin();
            dp1[i] = idx;
            mn1[idx] = h[i];
        }
    }

    reverse(h.begin(), h.end());
    vector<int> dp2(n), mn2(n+1);
    len = 1;
    dp2[0] = 1;
    mn2[1] = h[0];
    for(int i=1;i<n;++i) {
        if(h[i] > mn2[len]) {
            dp2[i] = ++len;
            mn2[len] = h[i];
        } else {
            int idx = lower_bound(mn2.begin()+1, mn2.begin()+len+1, h[i]) - mn2.begin();
            dp2[i] = idx;
            mn2[idx] = h[i];
        }
    }
    reverse(dp2.begin(), dp2.end());

    vector<int> sum(n);
    for(int i=0;i<n;++i) {
        sum[i] = dp1[i] + dp2[i];
    }
    sort(sum.begin(), sum.end());
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=0;i<n;++i) ans += sum[i] * a[i];
    cout << ans << '\n';

    return 0;
}