#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,b,k,q;cin>>n>>m>>b>>k>>q;
    int a[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    vector<pii> pos(b);
    for(int i=0;i<b;i++) cin>>pos[i].first>>pos[i].second;
    while(q--) {
        int x,y;cin>>x>>y;
        int ans=a[x][y];
        for(auto e:pos) if(abs(x-e.first)+abs(y-e.second)<=k) ans--;
        if(ans<0) ans=0;
        cout<<ans<<'\n';
    }
    return 0;
}