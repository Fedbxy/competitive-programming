#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    int l = 0, r = *max_element(a.begin(), a.end()) * k;
    while(l < r) {
        int mid = l + (r - l) / 2;

        int sum = 0;
        for(auto e: a) sum += mid / e;

        if(sum >= k) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}