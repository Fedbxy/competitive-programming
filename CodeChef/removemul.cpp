// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// ll func(ll n) {
//     return (n*(n+1))/2;
// }

// void solve() {
//     ll n,m;cin>>n>>m;
//     ll ans=func(n);
//     ll sum=0;
//     for(ll i=0;i<m;i++){
//         ll v;cin>>v;
//         sum+=v;
//     }
//     cout<<ans-sum<<'\n';
// }

// int main(){
//     ios::sync_with_stdio(false);cin.tie(0);
//     int t;cin>>t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll func(ll n) {
    return (n*(n+1))/2;
}

void solve() {
    int n,m;cin>>n>>m;
    ll ans=0;
    ll idxV=1;
    for(int i=0;i<m;i++){
        ll v;cin>>v;
        if(idxV!=v){
            ans+=func(v-1)-func(idxV-1);
            // cout<<"f:"<<v-1<<"f:"<<idxV-1<<" = "<<func(v-1)-func(idxV-1)<<'\n';
            idxV=v;
        }
        idxV++;
    }
    idxV--;
    // cout<<"f:"<<n<<"f:"<<idxV<<" = "<<func(n)-func(idxV)<<'\n';
    ans+=func(n)-func(idxV);
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}