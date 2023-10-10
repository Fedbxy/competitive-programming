#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

void solve() {
    int n;cin>>n;
    vector<pii> a;
    for(int i=0;i<n;i++) {
        int w,q;cin>>w>>q;
        if(w<=10) {
            a.push_back({q,i+1});
        }
    }
    sort(a.begin(),a.end(),greater<pii>());
    cout<<a[0].second<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}