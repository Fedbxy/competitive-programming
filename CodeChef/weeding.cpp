#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    int last;
    for(int i=0;i<n;i++){
        int v;cin>>v;
        if(i==n-1) last=v;
    }
    if(last+k-1<=m) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}