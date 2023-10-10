#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int> m;
    for(int i=0;i<n;i++) m[a[i]]=0;
    vector<int> sol(n+1);
    for(int i=1;i<=n;i++) {
        if(m[a[i-1]]==0) {
            // cout<<a[i]<<" ENTERED\n";
            sol[i]+=sol[i-1]+1;
            m[a[i-1]]++;
        } else if(m[a[i-1]]==1) {
            // cout<<a[i]<<" LEFT\n";
            sol[i]+=sol[i-1]-1;
            m[a[i-1]]--;
        }
    }
    // for(auto e:sol) cout<<e<<' ';
    // cout<<'\n';
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