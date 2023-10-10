#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m,n;cin>>m>>n;
    int k;cin>>k;
    vector<vector<int>> a(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> ps(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ps[i][j]=a[i][j]+ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
        }
    }
    int mx=INT_MIN;
    for(int i=1;i<=m-k;i++){
        for(int j=1;j<=n-k;j++){
            int sum=ps[i+k][j+k]-ps[i][j+k]-ps[i+k][j]+ps[i][j];
            if(sum>mx){
                mx=sum;
            }
        }
    }
    cout<<mx<<"\n";
    return 0;
}