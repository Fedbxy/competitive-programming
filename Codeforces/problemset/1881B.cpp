#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a,b,c;cin>>a>>b>>c;
    int mn = min({a,b,c});
    if(a%mn==0 and b%mn==0 and c%mn==0) {
        int cnt=0;
        while(a!=mn) {
            a-=mn;
            cnt++;
        }
        while(b!=mn) {
            b-=mn;
            cnt++;
        }
        while(c!=mn) {
            c-=mn;
            cnt++;
        }
        if(cnt<=3) cout<<"YES\n";
        else cout<<"NO\n";
    } else {
        cout<<"NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int t;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}