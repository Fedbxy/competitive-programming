#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;
int a[N];

void solve() {
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];

    int cnt = 0;
    for(int i=1;i<=n;++i) {
        if(a[i] == 1) {
            cnt += n;
            continue;
        }
        for(int j=1;j<=n;++j) {
            if(pow(a[i], j) > 1e9) break;
            if(pow(a[i], j) <= a[j]) ++cnt;
        }
    }
    cout << cnt << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}