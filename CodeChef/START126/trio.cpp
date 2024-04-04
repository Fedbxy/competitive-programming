#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    // map<int, set<int>> m;
    for(int i=0;i<n;i++) cin >> arr[i];//, m[arr[i]].insert(i);

    ll ans = 0;
    ll cnta = 0, cntb = 0;
    for(int i=0;i<n;i++) {
        // if(1.0 * arr[i] / (1.0 * arr[i] - 3) == floor(1.0 * arr[i] / (1.0 * arr[i] - 3))) x = 1.0 * arr[i] / (1.0 * arr[i] - 3);
        if(arr[i] == 6) cnta++;
        else if(arr[i] == 2) ans += cnta;
        else if(arr[i] == 4) cntb++;
    }
    cout << ans + cntb * (cntb - 1) / 2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
5
2 1 8 6 2
*/