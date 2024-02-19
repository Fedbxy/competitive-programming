#include <bits/stdc++.h>

using namespace std;

const int X = 1e6 + 10;
int dp[X];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,x;cin>>n>>x;
    vector<int> w(n+1);
    for(int i=0;i<=x;i++) dp[i] = INT_MAX - 1;
    dp[0] = 0;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) for(int j=0;j<=x;j++) {
        if(j >= w[i]) dp[j] = min(dp[j], 1 + dp[j-w[i]]);
    }
    cout<<(dp[x] == INT_MAX - 1 ? -1 : dp[x])<<'\n';
    return 0;
}