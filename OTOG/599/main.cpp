#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

bool cmp(const pii &l, const pii &r){
    if(l.first==r.first){
        return l.second>r.second;
    }
    return l.first<r.first;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end(),cmp);
    for(auto e:a) cout<<e.first<<" "<<e.second<<"\n";
    return 0;
}