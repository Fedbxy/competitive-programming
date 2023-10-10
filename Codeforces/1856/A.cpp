#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> a(n),b;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0,idx;
    b=a;
    sort(b.begin(),b.end());
    bool isBroken=false;
    for(int i=0;i<n;i++) {
        idx=n-i-1;
        if(a[idx]!=b[idx]) {
            isBroken=true;
            break;
        }
    }
    // for(int e:a) cout<<e<<' ';
    // cout<<'\n';
    // for(int e:b) cout<<e<<' ';
    // cout<<'\n';
    if(isBroken) {
        for(int i=0;i<=idx;i++) if(a[i]>ans) ans=a[i];
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}