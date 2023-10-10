#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> sol;
    for(int i=1;i<n-1;i++) {
        sol.push_back((a[i-1]+a[i]+a[i+1])%3);
    }
    for(auto e:sol) cout<<e<<' ';
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}