#include <bits/stdc++.h>    

using namespace std;
using ll = long long;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1) {
        cout<<"NO\n";
        return;
    }
    ll sum=0,oneplus=0,sum2=0;
    for(int i=0;i<n;i++) sum+=1LL*a[i];
    for(int i=0;i<n;i++) {
        if(a[i]==1) {
            a[i]=-1;
            oneplus++;
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i]>1 and oneplus>0) {
            a[i]--;
            oneplus--;
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i]==-1) a[i]=2;
    }
    for(int i=0;i<n;i++) sum2+=1LL*a[i];
    // cout<<oneplus<<'\n';
    // cout<<sum<<" "<<sum2<<'\n';
    // for(int i=0;i<n;i++) cout<<a[i]<<' ';
    // cout<<'\n';
    if(oneplus==0 and sum==sum2) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}