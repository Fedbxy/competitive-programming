#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int md = 1e8 + 3;
int dp[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    n+=1; m+=1;
    dp[1][1] = 1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!(i == 1 and j == 1)) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % md;
    cout << dp[n][m] << '\n';
    return 0;
}