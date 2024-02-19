#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10, X = 1e5 + 10;
vector<int> w(N), v(N);
// vector<vector<int>> dp(N, vector<int>(X, -1));
int dp[X];
int n,x;

// int func(int idx, int weight) {
//     if(idx == 0 or weight == 0) return 0;
//     if(dp[idx][weight] != -1) return dp[idx][weight];
//     int res = func(idx - 1, weight);
//     if(weight - w[idx] >= 0) res = max(res, v[idx] + func(idx - 1, weight - w[idx]));
//     return dp[idx][weight] = res;
// }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) for(int j=x;j>=0;j--) {
        if(j - w[i] >= 0) dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
    }
    int ans = INT_MIN;
    for(int i=1;i<=x;i++) ans = max(dp[i], ans);
    cout<<ans<<'\n';
    return 0;
}