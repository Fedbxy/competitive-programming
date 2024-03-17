#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<int> a(n), cost(n), pt(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cost[0] = abs(min(a[0], 0)); pt[0] = max(a[0], 0);
    for(int i=1;i<n;i++) cost[i] = cost[i-1] + abs(min(a[i], 0)), pt[i] = pt[i-1] + max(a[i], 0);
    while(m--) {
        int idx,money,ans,v;cin>>idx>>money;
        if(idx == 0) v = money;
        else v = money + cost[idx-1];
        auto itr = lower_bound(cost.begin() + idx, cost.end(), v);
        if(itr == cost.end()) ans = pt[itr - cost.begin() - 1];
        else ans = pt[itr - cost.begin()];
        if(idx != 0) ans -= pt[idx-1];
        cout<<ans<<'\n';
    }
    return 0;
}