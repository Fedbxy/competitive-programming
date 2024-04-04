#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(vector<int> &a, int k, ll x) {
    int cnt = 1;
    ll sum = 0;
    for(auto e:a) {
        sum += e;
        if(sum > x) cnt++, sum = e;
    }
    return cnt <= k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    ll l = INT_MIN, r = 0;
    for(auto e:a) r += e, l = max(l, (ll)e);
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(ok(a, k, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}