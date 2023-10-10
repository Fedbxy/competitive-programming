#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> ps(n);
    ps[0]=a[0];
    for(int i=1;i<n;i++) ps[i]=ps[i-1]+a[i];
    while(q--){
        int x;cin>>x;
        int idx=lower_bound(ps.begin(),ps.end(),x)-ps.begin();
        if(ps[idx]==x) cout<<idx+1<<'\n';
        else cout<<idx<<'\n';
    }
    return 0;
}