#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> dist(n, INT_MIN);
    vector<bool> flag(n);
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;

    int u = 0, round = n-1;
    ll ans = 0;
    dist[u] = 0;
    while(round--) {
        int next_u, mx = INT_MIN;
        flag[u] = true;

        for(int v=0;v<n;v++) {
            if(flag[v]) continue;
            dist[v] = max(dist[v], max(abs(a[u].first - a[v].first), abs(a[u].second - a[v].second)));
            if(dist[v] > mx) {
                mx = dist[v];
                next_u = v;
            }
        }

        u = next_u;
        ans += mx;
    }
    cout<<ans<<'\n';
    return 0;
}