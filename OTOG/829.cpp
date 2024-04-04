#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<ll> a(n+2);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<ll> sum(n);
    for(int i=1;i<n;i++) sum[i] = a[i-1] + a[i] + a[i+1];
    while(q--) {
        ll x; cin >> x;
        int idx = lower_bound(sum.begin(), sum.end(), x) - sum.begin();
        cout << idx << '\n';
    }
    return 0;
}