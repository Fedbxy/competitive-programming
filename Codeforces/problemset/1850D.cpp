#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    int ans=0;
    int cnt=0;
    for(int i=0;i<n-1;i++) {
        if(a[i+1]-a[i]<=k) cnt++;
        else {
            if(cnt!=0) ans=max(ans,cnt);
            cnt=0;
        }
    }
    if(cnt!=0) ans=max(ans,cnt);
    ans++;
    cout<<n-ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}