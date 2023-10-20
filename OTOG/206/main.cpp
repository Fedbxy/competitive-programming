#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,q;cin>>n>>m>>q;
    int a[n][m],row[n],col[m];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) row[i]+=a[i][j];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) col[i]+=a[j][i];
    while(q--) {
        int i,j;cin>>i>>j;
        cout<<row[i-1]+col[j-1]-a[i-1][j-1]<<'\n';
    }
    return 0;
}