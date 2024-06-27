#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

const int N = 5e4 + 10, K = 25;
vector<pii> adj[N];
int dist[N][K];
bool flag[N][K], state[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<N;++i) for(int j=0;j<K;++j) dist[i][j] = INT_MAX;

    int n, m, p, k, s; cin >> n >> m >> p >> k;
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for(int i=1;i<=p;++i) {
        int temp; cin >> temp;
        state[temp] = true;
    };
    cin >> s;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    dist[s][0] = 0;
    pq.push({{dist[s][0], s}, 0});
    while(!pq.empty()) {
        auto [e, cnt] = pq.top();
        auto [d, u] = e;
        pq.pop();

        if(flag[u][cnt]) continue;
        flag[u][cnt] = true;

        for(auto [v, w]: adj[u]) {
            if(!flag[v][cnt] and dist[v][cnt] > dist[u][cnt] + w) {
                dist[v][cnt] = dist[u][cnt] + w;
                pq.push({{dist[v][cnt], v}, cnt});
            }

            if(state[v] and cnt < k and dist[v][cnt+1] > dist[u][cnt] + w) {
                dist[v][cnt+1] = dist[u][cnt] + w;
                pq.push({{dist[v][cnt+1], v}, cnt+1});
            }
        }
    }

    // for(int i=1;i<=n;++i) {
    //     for(int j=0;j<=k;++j) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << (dist[s][k] == INT_MAX ? "NO FOOD :(" : to_string(dist[s][k])) << '\n';
    return 0;
}