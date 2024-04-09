#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(auto &e: arr) cin >> e;
    
    ll l_attack = (k + 1) / 2;
    ll r_attack = k - l_attack;
    
    ll sum = 0;
    for(auto &e: arr) {
        sum += e;
        if(sum > l_attack) {
            e = sum - l_attack;
            break;
        }
        e = 0;
    }

    reverse(arr.begin(), arr.end());
    sum = 0;
    for(auto &e: arr) {
        sum += e;
        if(sum > r_attack) {
            e = sum - r_attack;
            break;
        }
        e = 0;
    }

    ll ans = 0;
    for(auto e: arr) if(!e) ans++;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}