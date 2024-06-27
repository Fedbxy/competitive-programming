#include <bits/stdc++.h>

using namespace std;

const int N = 21;
double a[N][N];
double dp[1<<N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            cin >> a[i][j];
            a[i][j] /= 100;
        }
    }

    dp[0] = 1;
    for(int mask=1;mask<1<<n;++mask) {
        for(int i=1;i<=n;++i) {
            if(mask & (1 << (i-1))) {
                dp[mask] = max(dp[mask], dp[mask ^ (1 << (i-1))] * a[__builtin_popcount(mask)][i]);
            }
        }
    }

    cout << fixed << setprecision(12) << dp[(1<<n)-1] * 100 << '\n';
    return 0;
}