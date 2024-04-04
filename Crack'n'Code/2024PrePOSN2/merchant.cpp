// subtask M = N
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(vector<ll> &w, ll p, ll x) {
    ll cnt = 1, sum = 0;
    for(auto e:w) {
        sum += e;
        if(sum > x) {
            sum = e;
            cnt++;
        }
    }
    return cnt <= p;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> v(n), w(n);
    ll sum = 0;
    for(int i=0;i<n;i++) cin >> v[i] >> w[i], sum += v[i];
    
    ll l = 0, r = sum;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(ok(w, p, mid)) r = mid;
        else l = mid + 1;
    }
    cout <<  sum - r * r << '\n'; 
    return 0;
}