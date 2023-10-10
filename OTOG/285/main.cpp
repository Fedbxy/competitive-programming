#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    while(m--){
        int x;cin>>x;
        int idx=lower_bound(a.begin(),a.end(),x)-a.begin();
        if(a[idx]==x) cout<<a[idx]<<'\n';
        else if(idx<=0) cout<<-1<<'\n';
        else cout<<a[idx-1]<<'\n';
    }
    return 0;
}