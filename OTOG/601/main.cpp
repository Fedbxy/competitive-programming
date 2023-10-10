#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        if(l>r) swap(l,r);
        int l_idx=lower_bound(a.begin(),a.end(),l)-a.begin();
        int r_idx=upper_bound(a.begin(),a.end(),r)-a.begin();
        cout<<r_idx-l_idx<<'\n';
    }
    return 0;
}