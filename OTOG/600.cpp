#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end(), greater<pii>());
    int l=a[0].first,r=a[0].second;
    vector<pii> ans;
    for(int i=1;i<n;i++) {
        if(!(l>=a[i].first and r>=a[i].second)) {
            ans.push_back({l,r});
            l=a[i].first;
            r=a[i].second;
        }
    }
    ans.push_back({l,r});
    sort(ans.begin(), ans.end());
    for(auto e:ans) cout<<e.first<<' '<<e.second<<'\n';
}