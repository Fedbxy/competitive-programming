#include <bits/stdc++.h>

#define int long long
#define INT_MAX LLONG_MAX

using namespace std;
using pii = pair<int, int>;

int dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int zx, zy, r; cin >> zx >> zy >> r;
    vector<pii> a(n), warp;
    for(int i=0;i<n;i++) {
        cin >> a[i].first >> a[i].second;
        auto [x, y] = a[i];
        if((zx - x) * (zx - x) + (zy - y) * (zy - y) <= r * r) warp.emplace_back(x, y);
    }

    int ans = dist(a[0], a[n-1]);
    int mnS = INT_MAX, mnT = INT_MAX;  
    for(auto e:warp) {
        mnS = min(mnS, dist(a[0], e));
        mnT = min(mnT, dist(a[n-1], e));
        ans = min(ans, mnS + mnT);
    }
    cout << ans << '\n';
    return 0;
}