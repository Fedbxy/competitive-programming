// written by fed
// score: 5/5

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]+=max(a[i-1][j],a[i][j-1]);
    cout<<a[n][m]<<'\n';
    return 0;
}