#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<char>> a(n+1, vector<char> (n+1));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];

    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j] = a[i][j] == '*' ? 0 : ((i == 1 and j == 1) ? 1 : (dp[i-1][j] + dp[i][j-1]) % md);
    cout << dp[n][n] << '\n';
}