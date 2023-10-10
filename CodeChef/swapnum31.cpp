#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

void solve() {
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    if(n<=1){
        for(int e:a) cout<<e<<' ';
        cout<<'\n';
        return;
    }
    vector<pii> b(n);
    for(int i=0; i<n; i++){
        b[i]={a[i],i};
    }
    sort(b.begin(), b.end());
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(abs(b[i].second-b[j].second)>=k and b[i].first>b[j].first){
                // cout<<"SWAPPING "<<b[i].second<<" AND "<<b[j].second<<'\n';
                swap(a[b[i].second],a[b[j].second]);
            }else{
                // break;
            }
        }
    }
    for(int e:a) cout<<e<<' ';
    cout<<'\n';
    // for(auto e:b) cout<<e.first<<' '<<e.second<<' ';
    // cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}