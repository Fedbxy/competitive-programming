#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using ppi = pair<pii,ll>;

bool cmp(const ppi &l, const ppi &r) {
    if(l.first.first==r.first.first) {
        if(l.first.second==r.first.second) {
            return l.second<r.second;
        }
        return l.first.second < r.first.second;
    }
    return l.first.first > r.first.first;
}

void solve() {
    ll n,m,h;cin>>n>>m>>h;
    vector<ll> a[n];
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            ll x; cin>>x;
            a[i].push_back(x);
        }
    }
    for(ll i=0;i<n;i++) sort(a[i].begin(),a[i].end());
    vector<ppi> ans;
    for(ll i=0;i<n;i++){
        ll score=0,time=0,penalties=0;
        for(ll j=0;j<m;j++) {
            if(a[i][j]+time<=h) {
                time+=a[i][j];
                penalties+=time;
                score++;
            } else {
                break;
            }
        }
        ans.push_back({{score,penalties},i});
    }
    sort(ans.begin(),ans.end(),cmp);
    if(ans.size()==1) {
        cout<<1<<'\n';
        return;
    }
    // ppi prev={{ans[0].first.first,ans[0].first.second},ans[0].second};
    // for(ll i=1;i<ans.size();i++) {
    //     ppi temp={{ans[i].first.first,ans[i].first.second},ans[i].second};
    //     // if(ans[i].first.first==prev.first.first and ans[i].first.second==prev.first.second) ans.erase(ans.begin()+i);
    //     prev=temp;
    // }
    // for(auto e:ans) cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<'\n';
    for(ll i=0;i<ans.size();i++) {
        if(ans[i].second==0) {
            cout<<i+1<<'\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}