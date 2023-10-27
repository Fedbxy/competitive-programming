#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>b[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cout<<a[i][j]+b[i][j]<<(j==m-1 ? '\n' : ' ');
    return 0;
}