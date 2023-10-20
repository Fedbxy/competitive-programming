#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mx = *max_element(a.begin(), a.end());
    while(m--) {
        int q,ans;cin>>q;
        if(q%mx==0) ans = q/mx;
        else ans = q/mx + 1;
        cout<<ans<<'\n';
    }
    return 0;
}