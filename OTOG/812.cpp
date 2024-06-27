#include <bits/stdc++.h>

using namespace std;

const int N = 25;
int a[N+1][N+1];
int dp[1<<N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<1<<N;++i) dp[i] = INT_MAX;

    int n; cin >> n;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin >> a[i][j];

    // dp[0] = 0;
    // for(int mask=1;mask<1<<n;++mask) {
    //     for(int i=1;i<=n;++i) {
    //         if(mask & (1 << (i - 1))) {
    //             dp[mask] = min(dp[mask], dp[mask ^ (1 << (i - 1))] + a[__builtin_popcount(mask)][i]);
    //         }
    //     }
    // }

    dp[0] = 0;
    for(int mask=0;mask<1<<n;++mask) {
        for(int i=1;i<=n;++i) {
            if(mask & (1 << (i - 1))) continue;
            int newmask = mask | 1 << (i - 1);
            dp[newmask] = min(dp[newmask], dp[mask] + a[__builtin_popcount(newmask)][i]);
        }
    }

    cout << dp[(1<<n)-1] << '\n';
    return 0;
}