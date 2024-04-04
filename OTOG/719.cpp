#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;

    int ans = 0;
    vector<int> dist(n, INT_MIN);
    dist[0] = 0;
    for(int u=0;u<n-1;u++) {
        int next_u, mx = INT_MIN;
        for(int v=u+1;v<n;v++) {
            dist[v] = max(dist[v], max(abs(a[u].first - a[v].first), abs(a[u].second - a[v].second)));
            if(dist[v] > mx) {
                mx = dist[v];
                next_u = v;
            }
        }
        swap(a[u+1], a[next_u]);
        swap(dist[u+1], dist[next_u]);
        ans += mx;
    }
    cout << ans << '\n';
    return 0;
}