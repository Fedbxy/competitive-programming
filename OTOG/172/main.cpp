#include <bits/stdc++.h>

using namespace std;

int n,m;
const int N=15;
int a[N][N];
int ans=INT_MIN;

void recur(int i,int j,int sum){
    sum+=a[i][j];
    if(i==n-1 and j==m-1){
        ans=max(ans,sum);
        return;
    }
    if(i<n-1) recur(i+1,j,sum);
    if(j<m-1) recur(i,j+1,sum);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    recur(0,0,0);
    cout<<ans<<'\n';
    return 0;
}