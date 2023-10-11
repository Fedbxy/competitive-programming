#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> a(3);
    for(int i=0;i<3;i++) cin>>a[i];
    bool found=0;
    for(int i=0;i<3;i++) {
        int x=a[i],sum=1;
        for(int j=0;j<3;j++) if(j!=i) sum*=a[j];
        // cout<<"# "<<sum<<' '<<x<<'\n';
        if(sum%x==0) {
            cout<<sum<<' '<<x<<'\n';
            found=1;
            break;
        }
    }
    if(!found) cout<<-1<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}