#include <bits/stdc++.h>

using namespace std;
using pii = pair<double, double>;

double area(pii a, pii b, pii c) {
    return 0.5 * abs(a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &e: a) cin >> e.first >> e.second;

    vector<double> dp(1<<n);
    for(int mask=0;mask<1<<n;++mask) {
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                for(int k=j+1;k<n;++k) {
                    if((mask & (1 << i)) or (mask & (1 << j)) or (mask & (1 << k))) continue;
                    int newmask = mask | 1 << i | 1 << j | 1 << k;
                    dp[newmask] = max(dp[newmask], dp[mask] + area(a[i], a[j], a[k]));
                }
            }
        }
    }
    // for(int i=0;i<1<<n;++i) cout << dp[i] << ' ';
    // cout << '\n';
    cout << fixed << setprecision(2) << dp[(1<<n)-1] << '\n';
    return 0;
}