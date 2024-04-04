#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;

    vector<map<ll, int>> dist(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) continue;
            ll d = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
            dist[i][d] = j;
        }
    }

    int ans = 0;
    while(m--) {
        ll s; cin >> s;
        int u = 0;
        while(u != n-1) {
            ans++;
            auto itr = dist[u].lower_bound(s);
            if((*itr).first != s) u = (*itr).second - 1;
            else u = (*itr).second;
        }
        
    }
    return 0;
}