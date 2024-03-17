#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1, a.end(), greater<int>());
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++) dp[i]+=dp[i-1]+a[i];
    while(m--) {
        int q;cin>>q;
        if(q==0) {
            cout<<0<<'\n';
            continue;
        }
        int ans = lower_bound(dp.begin()+1, dp.end(), q) - dp.begin();
        if(ans==n+1) cout<<"NO\n";
        else cout<<ans<<'\n';
    }
    return 0;
}