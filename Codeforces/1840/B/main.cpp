#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        if(k>=30) cout<<n+1<<'\n';
        else cout<<min(n+1, ll(pow(2,k)))<<'\n';
    }
    return 0;
}