#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int v;
    vector<int> a;
    while(cin>>v) a.push_back(v);
    reverse(a.begin(), a.end());
    int idx=0,ans=0;
    while(idx<a.size()) {
        idx+=a[idx];
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}