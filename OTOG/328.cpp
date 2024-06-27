#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    int l = 0, r = *max_element(a.begin(), a.end()) * m;
    while(l < r) {
        int mid = l + (r - l) / 2;

        int cnt = 0;
        for(auto e: a) cnt += mid / e;
        
        if(cnt >= m) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}