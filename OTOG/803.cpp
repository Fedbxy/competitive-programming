#include <bits/stdc++.h>

using namespace std;

const int N = 210, R = 500;
const int md = 1e7+9;
int n, m, r;
char a[N][N];
int dp[N][N][R];
bool flag[N][N][R];

int recur(int i, int j, int t) {
    if(i == 1 and j == 1) return 1;
    if(i == 0 or j == 0) return 0;
    if(flag[i][j][t]) return dp[i][j][t];
    flag[i][j][t] = true;

    int res = 0;
    if(a[i][j] == 'X' and t > 0) res = (recur(i-1, j, t-1) + recur(i, j-1, t-1)) % md;
    else if(a[i][j] == '.') res = (recur(i-1, j, t) + recur(i, j-1, t)) % md;

    return dp[i][j][t] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // memset(dp, -1, sizeof(dp));
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];

    cout << recur(n, m, min(r, n+m-1)) << '\n';
    return 0;
}