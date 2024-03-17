#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
int dp[N][3],a[N][3];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i][0];
        dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+a[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][2])+a[i][2];
    }
    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<3;j++) {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<'\n';
    return 0;
}