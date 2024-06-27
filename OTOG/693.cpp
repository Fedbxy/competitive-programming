// #include <bits/stdc++.h>

// #define int long long
// #define INT_MAX LLONG_MAX

// using namespace std;
// using pii = pair<int, int>;
// using ppi = pair<pii, int>;

// const int N = 2e3 + 10;
// vector<pii> adj[N];
// int dist[N];
// vector<pii> sol[N];

// signed main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     for(int i=0;i<N;++i) dist[i] = INT_MAX;

//     int n, m, s, t; cin >> n >> s >> t >> m;
//     for(int i=0;i<m;++i) {
//         int u, v, w; cin >> u >> v >> w;
//         adj[u].emplace_back(v, w);
//     }

//     priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
//     dist[s] = 0;
//     pq.push({{dist[s], s}, 0});
//     while(!pq.empty()) {
//         auto [e, cnt] = pq.top();
//         auto [d, u] = e;
//         pq.pop();

//         for(auto [v, w]: adj[u]) {
//             sol[v].push_back({d + w, cnt + 1});
//             if(dist[v] > d + w) {
//                 dist[v] = d + w;
//                 pq.push({{dist[v], v}, cnt+1});
//             }
//         }
//     }

//     // for(int i=0;i<n;++i) {
//     //     for(auto e: sol[i]) {
//     //         cout << e.first << ' ' << e.second << " | ";
//     //     }
//     //     cout << '\n';
//     // }

//     int q; cin >> q;
//     while(q--) {
//         int x; cin >> x;
//         int ans = INT_MAX;
//         for(auto e: sol[t]) {
//             ans = min(ans, e.first + x * (e.second - 1));
//         }
//         cout << ans << ' ';
//     }
//     cout << '\n';

//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
#define INT_MAX LLONG_MAX

using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

const int N = 2e3 + 10, M = 1e4 + 10;
vector<pii> adj[N];
int dist[N][M];
bool flag[N][M];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<N;++i) for(int j=0;j<M;++j) dist[i][j] = INT_MAX;

    int n, m, s, t; cin >> n >> s >> t >> m;
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

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
            if(cnt < n - 1 and dist[v][cnt+1] > d + w) {
                dist[v][cnt+1] = d + w;
                pq.push({{dist[v][cnt+1], v}, cnt+1});
            }
        }
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        int ans = INT_MAX;
        for(int i=0;i<=n-1;++i) {
            if(dist[t][i] == INT_MAX) continue;
            ans = min(ans, dist[t][i] + x * (i - 1));
        }
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}