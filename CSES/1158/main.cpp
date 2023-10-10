#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;
const int X=1e5+10;

int w[N];
int v[N];
int dp[N][X];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,x;cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=x;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<'\n';
    return 0;
}

/*
    1. dp[i][j] max value a[1...i]; j<=x
    2. dp[i][0]=dp[0][j]=0
    3. dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v,dp[i][j-1])
    4. max(dp[n][j])
*/