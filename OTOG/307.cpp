#include <bits/stdc++.h>

using namespace std;

const int M = 1e4 + 10;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> dp(M, INT_MAX); dp[0] = 0;
    for(int i=0;i<n;i++) cin >> a[i], dp[a[i]] = 1;
    
    for(int i=1;i<=m;i++) {
        for(int j=0;j<n;j++) {
            if(i - a[j] >= 0) {
                dp[i] = min(dp[i], dp[i-a[j]] + 1);
            }
        }
    }

    cout << dp[m] << '\n';
    return 0;
}