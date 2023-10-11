#include <bits/stdc++.h>

using namespace std;

const int N = 1500;

void solve() {
    int n;cin>>n;
    vector<int> sol(N);
    vector<int> a(n),d(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>d[i];
    for(int i=0;i<n;i++) {
        sol[a[i]]++;
        sol[d[i]]++;
    }
    sort(sol.begin(),sol.end(),greater<int>());
    cout<<sol[0]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}