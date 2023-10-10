#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll ans;
        ans=(n*(n+2)+2);
        cout<<ans<<'\n';
    }
    return 0;
}