#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N=250+10;
int a[N][N];
int dp[N][N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dp[1][1]=a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}

/*
    1. dp[i][j] -> max sum from (0,0)->(i,j)
    2. dp[1][1]=a[1][1]
    3. dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j]
    4. dp[n][m]

3 3
5 19 47
75 3 1
4 5 24
*/