#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];
int dp[N][N][3];

int recur(int l, int r, int t) {
    if(l > r) return 0;
    if(dp[l][r][t] != -1) return dp[l][r][t];

    int res;
    if(t==1) res = max(recur(l+1, r, 2) + a[l], recur(l, r-1, 2) + a[r]);
    else res = max(recur(l+1, r, 1), recur(l, r-1, 1));

    return dp[l][r][t] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    int n; cin >> n; n *= 2;
    for(int i=1;i<=n;i++) cin >> a[i];

    cout << recur(1, n, 1) << '\n';
    return 0;
}