#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    double n,d,h;cin>>n>>d>>h;
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    double ans=0;
    // double y;
    // for(double e:a) cout<<e<<' ';
    // cout<<'\n';
    for(int i=0;i<n-1;i++) {
        // cout<<a[i]<<' '<<a[i+1]<<'\n';
        if(a[i+1]-a[i]<h) {
            // cout<<"#1\n";
            double hx=(h-(a[i+1]-a[i]));
            double dx=(hx*d)/h;
            ans+=((1.0/2.0)*d*h - (1.0/2.0)*dx*hx);
        } else {
            // cout<<"#2\n";
            ans+=((1.0/2.0)*d*h);
        }
    }
    ans+=((1.0/2.0)*d*h);
    cout<<fixed<<setprecision(7)<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // int t=1;cin>>t;
    // while(t--) {
    //     solve();
    // }
    cout<<0.5*200000-0.5*1/200000<<'\n';
    return 0;
}