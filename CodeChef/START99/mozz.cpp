#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x,y,r;cin>>x>>y>>r;
    double extra = r/30,total = extra+x;
    double ans = total/y;
    if(ans==floor(ans)) {
        cout<<int(ans)<<'\n';
    } else cout<<int(floor(ans)+1)<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}