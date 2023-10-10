/*
    1. dp[i][j]=sum of possible path (1,1)->(i,j)
    2. dp[1][1]=1;
    3. dp[i][j]=dp[i-1][j]+dp[i][j-1] (if its not trap)
    4. dp[n][n]
*/

#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;
char a[N][N];
int dp[N][N];
int md=1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 and j==1){
                if(a[i][j]!='*') dp[i][j]=1;
                else dp[i][j]=0;
                continue;
            }
            if(a[i][j]=='*') dp[i][j]=0;
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%md;
        }
    }
    cout<<dp[n][n]<<'\n';
    return 0;
}