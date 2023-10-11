#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fac(ll n) {
    if(n==0) return 1;
    ll ans=1;
    for(ll i=1;i<=n;i++) ans*=i;
    return ans;
}

ll func(ll n) {
    // cout<<n<<"!/("<<n-2<<"!2!)\n";
    // if(n<2) return 0;
    // cout<<"valid???   "<<n<<"!/("<<n-2<<"!2!)\n";
    // cout<<fac(n)<<"/"<<fac(n-2)*fac(2)<<"\n";
    // return (fac(n))/(fac(n-2)*fac(2));

    return (n*(n-1))/2;
}

void solve() {
    int n,q;cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> p(n+1);
    for(ll i=1;i<=n;i++) {
        p[i]=func(n-i)+p[i-1];
        // cout<<p[i]<<'\n';
    }
    // for(ll e:p) cout<<e<<' ';
    // cout<<'\n';
    while(q--) {
        ll qry;cin>>qry;
        ll idx=lower_bound(p.begin(),p.end(),qry)-p.begin();
        cout<<a[idx-1]<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}