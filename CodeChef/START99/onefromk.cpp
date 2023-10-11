#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i]*1LL;
    }
    cout<<sum<<' ';
    for(int i=0;i<n-1;i++) {
        sum-=a[i];
        cout<<sum<<' ';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}