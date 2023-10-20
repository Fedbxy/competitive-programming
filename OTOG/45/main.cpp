#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    int k;cin>>k;
    int a[n][m],ps[n+1][m+1],mx=INT_MIN;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n-k+1;i++) {
        for(int j=0;j<m-k+1;j++) {
            int sum=0;
            for(int x=i;x<i+k;x++) {
                for(int y=j;y<j+k;y++) {
                    sum+=a[x][y];
                }
            }
            mx=max(mx,sum);
        }
    }
    // memset(ps, 0, sizeof(ps));
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i-1][j-1];
    //     }
    // }
    // for(int i=k;i<=n;i++) {
    //     for(int j=k;j<=m;j++) {
    //         int sum = ps[i][j]-ps[i-k][j]-ps[i][j-k]+ps[i-k][j-k];
    //         mx=max(sum,mx);
    //     }
    // }
    cout<<mx<<'\n';
    return 0;
}