#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

void solve() {
    int n;cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    int x=a[0].first,y=a[0].second;
    for(int i=0;i<n;i++) {
        if(a[i].first>x) x=a[i].first;
        if(a[i].second<y) y=a[i].second;
    }
    if(x<y) cout<<"no\n";
    else cout<<"yes\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("i.txt","r",stdin);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}