#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10, md = 1e9 + 7;
int dp[N][N];
char a[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    if(a[1][1] != '*') dp[1][1] = 1;
    else dp[1][1] = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        if(i == 1 and j == 1) continue;
        if(a[i][j] == '*') dp[i][j] = 0;
        else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % md;
    }
    cout<<dp[n][n]<<'\n';
    return 0;
}