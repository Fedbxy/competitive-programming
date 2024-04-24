#include <bits/stdc++.h>

using namespace std;

const vector<int> a = {0, 50, 25, 10, 5, 1};
const int md = 1e6 + 3;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        int dp[6][x+1];
        for(int i=0;i<=x;++i) dp[0][i] = 0;
        for(int i=0;i<=5;++i) dp[i][0] = 1;
        for(int i=1;i<=5;++i) {
            for(int j=0;j<=x;++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i][j - a[i]]) % md;
            }
        }
        cout << dp[5][x] << '\n';
    }
    return 0;
}