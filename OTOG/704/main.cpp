#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("i.txt","r",stdin);

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        a[i]=temp;
        cin>>temp;
        a[i]+=temp;
        // cout<<a[i]<<'\n';
    }

    vector<int> ps(n+1);
    for(int i=1;i<=n;i++) {
        ps[i]=ps[i-1]+a[i-1];
        // cout<<ps[i]<<'\n';
    }

    int t;cin>>t;
    while(t--) {
        int v;cin>>v;
        int ans=lower_bound(ps.begin(),ps.end(),v)-ps.begin();
        if(ps[ans]==v) ans++;
        cout<<ans-1<<'\n';
    }

    return 0;
}