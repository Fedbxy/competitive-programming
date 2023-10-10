#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;

    if(n==1){
        cout<<0<<'\n';
        return;
    }

    int ans=0;
    bool state=0;
    bool confirm=0;
    for(int i=0;i<n;i++){
        if(state and confirm and s[i]==':'){
            ans++;
            confirm=0;
            // cout<<i<<" COUNTED\n";
        }else if(state and s[i]==')'){
            confirm=1;
            // cout<<i<<" CONFIRMED\n";
        }else if(s[i]==':'){
            state=1;
            // cout<<i<<" STATED\n";
        }else{
            confirm=0;
            state=0;
            // cout<<i<<" FAILED\n";
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}