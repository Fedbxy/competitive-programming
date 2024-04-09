#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = 1e18;

bool ok(vector<ll> &arr, int k, ll x) {
    int cnt = 0;
    ll sum = 0;
    for(auto e: arr) {
        sum += e;
        if(sum >= x) {
            sum = 0;
            cnt++;
        }
    }
    if(sum) cnt++;
    return cnt <= k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    for(auto &e: arr) cin >> e;

    while(q--) {
        int k; cin >> k;
        ll l = 0, r = INF;
        while(l < r) {
            ll mid = l + (r - l) / 2;
            if(ok(arr, k, mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << '\n';
    }
    return 0;
}