// written by fed
// score: 5/5

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> mx(m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) mx[i]=max(mx[i],a[j][i]);
    int ans=0;
    for(auto e:mx) ans+=e;
    cout<<ans<<'\n';
    return 0;
}