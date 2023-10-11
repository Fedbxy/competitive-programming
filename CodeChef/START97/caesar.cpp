#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;cin>>n;
    string s,t,u;cin>>s>>t>>u;
    
    int k=0;
    while(s[0]!=t[0]){
        s[0]++;
        k++;
        if(s[0]>'z') s[0]-=26;
    }
    // cout<<k<<'\n';

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            u[i]++;
            if(u[i]>'z') u[i]-=26;
        }
    }
    cout<<u<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}