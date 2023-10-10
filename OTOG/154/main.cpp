#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n,q;cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++) ps[i]=1LL*(ps[i-1]+a[i-1]);
    // for(int i=1;i<=n;i++) cout<<ps[i]<<'\n';
    while(q--) {
        int a,b;cin>>a>>b;
        cout<<ps[b+1]-ps[a]<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int t;cin>>t;
    while(t--) {
        solve();
        if(t!=0) cout<<'\n';
    }
    return 0;
}