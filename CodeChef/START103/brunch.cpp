#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int a,b;cin>>a>>b;
        int ans=a/b;
        if(ans>20) ans=20;
        cout<<ans<<'\n';
    }
    return 0;
}