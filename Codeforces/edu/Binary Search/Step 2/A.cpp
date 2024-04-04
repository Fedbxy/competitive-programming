#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll w, h, n; cin >> w >> h >> n;
    ll l = max(w, h), r = 1;
    while((r / w) * (r / h) < n) r *= 2;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if((mid / w) * (mid / h) >= n) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}