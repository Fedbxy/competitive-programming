#include <bits/stdc++.h>

#define mp(x, y) make_pair(x, y)

using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

const int N = 1e5 + 10, K = 4;
vector<pii> adj[N];
int dist[N][K];
bool flag[N][K];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<N;++i) for(int j=0;j<K;++j) dist[i][j] = INT_MAX;

    int n, m, k; cin >> n >> m >> k;
    int s, t; cin >> s >> t;
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    dist[s][1] = 0;
    pq.emplace(mp(dist[s][1], s), 1);
    while(!pq.empty()) {
        auto [e, cnt] = pq.top();
        auto [d, u] = e;
        pq.pop();

        if(flag[u][cnt]) continue;
        flag[u][cnt] = true;

        for(auto [v, w]: adj[u]) {
            if(cnt < k and dist[v][cnt+1] > d + w) {
                dist[v][cnt+1] = d + w;
                pq.emplace(mp(dist[v][cnt+1], v), cnt+1);
            }

            if(cnt == k and dist[v][1] > d + w) {
                dist[v][1] = d + w;
                pq.emplace(mp(dist[v][1], v), 1);
            }
        }
    }

    if(k == 1) cout << (dist[t][1] == INT_MAX ? -1 : dist[t][1]) << '\n';
    else cout << (dist[t][2] == INT_MAX ? -1 : dist[t][2]) << '\n';

    return 0;
}