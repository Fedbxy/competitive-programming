#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a,b,c;cin>>a>>b>>c;
    if(a+b>=10) {
        cout<<"YES\n";
        return;
    }else if(a+c>=10) {
        cout<<"YES\n";
        return;
    }else if(b+c>=10) {
        cout<<"YES\n";
        return;
    }else{
        cout<<"NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}