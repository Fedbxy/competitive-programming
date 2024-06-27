#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
int a[N];
int dp[N][N];
int dp2[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];

    for(int sz=1;sz<=n;++sz) {
        for(int i=1;i<=n-sz+1;++i) {
            int j = i + sz - 1;
            dp[i][j] = max({dp[i][j], dp[i][j-1] + a[j], dp[i+1][j] + a[i]}) + abs(a[i] - a[j]);
        }
    }

    for(int sz=1;sz<=n;++sz) {
        dp2[sz] = dp[1][sz];
        for(int cut=1;cut<sz;++cut) {
            dp2[sz] = max(dp2[sz], dp2[cut] + dp[cut+1][sz]);
        }
    }

    cout << dp2[n] << '\n';

    return 0;
}