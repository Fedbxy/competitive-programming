#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<ll> psa(n+1), psb(n+1);
    for(int i=1;i<=n;i++) psa[i] = psa[i-1] + a[i-1];
    for(int i=1;i<=n;i++) psb[i] = psb[i-1] + b[i-1];

    for(int i=1;i<n;i++) psa[i+1] = max(psa[i], psa[i+1]);
    for(int i=1;i<n;i++) psb[i+1] = max(psb[i], psb[i+1]);

    vector<ll> c(n);
    for(int i=0;i<n;i++) c[i] = psa[i+1] + psb[i+1];

    while(q--) {
        ll x; cin >> x;
        int ans = lower_bound(c.begin(), c.end(), x) - c.begin() + 1;
        cout << min(ans, n) << '\n';
    }
    return 0;
}