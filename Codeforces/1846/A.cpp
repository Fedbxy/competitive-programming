#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin>>n;
    int cnt=0;
    while(n--) {
        int a,b; cin>>a>>b;
        if(a>b) cnt++;
    }
    cout<<cnt<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}