#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int x,y,z;cin>>x>>y>>z;
    vector<pii> a(y);
    vector<int> cnt(x),b(y);
    for(int i=0;i<y;i++) cin>>a[i].first>>a[i].second;
    for(int i=0;i<z;i++) {
        int v;cin>>v;
        b[v-1]++;
    }
    for(int i=0;i<y;i++) for(int j=a[i].first-1;j<a[i].second;j++) cnt[j]+=b[i];

    for(int i=0;i<x;i++) {
        cout<<cnt[i]<<'\n';
    }
    return 0;
}