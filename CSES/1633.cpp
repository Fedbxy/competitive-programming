#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=6;j++) if(i - j >= 0) dp[i] = (dp[i] + dp[i-j]) % md;
    }
    cout<<dp[n]<<'\n';
    return 0;
}