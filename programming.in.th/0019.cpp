#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int ans=INT_MAX;

void func(vector<pii> a, vector<pii> select, int idx) {
    if(idx == a.size()) {
        if(select.size()==0) return;
        int s = 1, b = 0;
        for(auto e:select) {s*=e.first;b+=e.second;}
        ans = min(ans,abs(s-b));
        return;
    }
    func(a, select, idx + 1);
    select.push_back(a[idx]);
    func(a, select, idx + 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    func(a,{},0);
    cout<<ans<<'\n';
    return 0;
}