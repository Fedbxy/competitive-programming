#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pli = pair<ll, ll>;
using pil = pair<ll, ll>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pil> adj[n+1];
    for(int i=0;i<m;i++) {
        int u, v;
        ll w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<ll> dist(n+1, 1e18), cnt(n+1), mn(n+1), mx(n+1);
    vector<bool> flag(n+1);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[1] = 0;
    cnt[1] = 1;
    pq.emplace(dist[1], 1);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) {
            ll alt = d + w;
            if(dist[v] == alt) {
                cnt[v] += cnt[u];
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            } else if(dist[v] > alt) {
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                dist[v] = alt;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << dist[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
    return 0;
}

/*
5 7
1 3 3
1 2 2
3 4 3
4 5 3
3 5 4
2 4 2
1 4 4
*/