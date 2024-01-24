#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<pii> a(n);
    vector<bool> flag(n);
    vector<int> dist(n, INT_MAX);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

    int u = 0, round = n-1;
    ll ans = 0;
    dist[u] = 0;
    multiset<int> select;
    while(round--) {
        int next_u, mn = INT_MAX;
        flag[u] = true;

        for(int v=0;v<n;v++) {
            if(flag[v]) continue;
            dist[v] = min(dist[v], abs(a[u].first - a[v].first) + abs(a[u].second - a[v].second));
            if(dist[v] < mn) {
                mn = dist[v];
                next_u = v;
            }
        }
        u = next_u;
        ans += mn;
        select.insert(mn);
    }
    
    auto itr = select.rbegin();
    for(int i=0;i<k-1;i++) {
        ans -= *itr;
        itr++;
    }
    cout<<ans<<'\n';
    return 0;
}