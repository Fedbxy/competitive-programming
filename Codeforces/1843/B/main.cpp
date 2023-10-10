#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;cin>>n;
    vector<ll> a;
    for(int i=0;i<n;i++){
        ll v;cin>>v;
        if(v!=0) a.push_back(v);
    }
    n=a.size();
    ll sum=0,ans=0;
    for(int i=0;i<n;i++) sum+=abs(a[i]);
    for(int i=1;i<n;i++){
        if(a[i]>0 and a[i-1]<0){
            ans++;
        }
    }
    if(n-1>=0 and a[n-1]<0) ans++;
    cout<<sum<<" "<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}