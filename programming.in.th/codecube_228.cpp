#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using ppi = pair<pli, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, t; cin >> n >> m >> k >> t;
    vector<pii> adj[n+1];
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll dist[n+1][2]; for(int i=1;i<=n;i++) dist[i][0] = dist[i][1] = 1e10;
    bool flag[n+1][2]; memset(flag, false, sizeof(flag));
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    dist[1][0] = 0;
    pq.push({{dist[1][0], 1}, 0});
    while(!pq.empty()) {
        ll d = pq.top().first.first;
        int u = pq.top().first.second, cnt = pq.top().second;
        pq.pop();

        if(flag[u][cnt]) continue;
        flag[u][cnt] = true;

        for(auto [v, w]:adj[u]) {
            if(!flag[v][cnt] and dist[v][cnt] > d + w) dist[v][cnt] = d + w, pq.push({{dist[v][cnt], v}, cnt});
            if(cnt == 0 and !flag[v][cnt+1] and dist[v][cnt+1] > d + k) dist[v][cnt+1] = d + k, pq.push({{dist[v][cnt+1], v}, cnt+1});
        }
    }

    int ans = min(dist[n][0], dist[n][1]);
    if(ans <= t) {
        cout << "Happy Winnie the Pooh :3\n";
        cout << ans << '\n';
    } else cout << "No Honey TT\n";
    return 0;
}