// #include <bits/stdc++.h>

// #define int long long
// #define INT_MAX 1e18

// using namespace std;
// using pii = pair<int, int>;

// const int N = 5e2 + 10;
// vector<pii> adj[N];
// bool flag[N];
// int b1, b2;
// int dist[N];
// set<pii> bridge;

// void dfs(int u) {
//     flag[u] = true;

//     for(auto [v, w]: adj[u]) {
//         if(flag[v]) continue;
//         if(u == b1 and v == b2) continue;
//         if(u == b2 and v == b1) continue;
//         dfs(v);
//     }
// }

// signed main() {
//     cin.tie(nullptr)->sync_with_stdio(false);

//     int n, m, q; cin >> n >> m >> q;

//     if(n > 500) {
//         return 0;
//     }

//     for(int i=0;i<m;++i) {
//         int u, v, w; cin >> u >> v >> w;
//         adj[u].emplace_back(v, w);
//         adj[v].emplace_back(u, w);
//     }

//     for(int u=0;u<n;++u) {
//         for(auto [v, w]: adj[u]) {
//             for(int i=0;i<n;++i) flag[i] = false;
//             b1 = u;
//             b2 = v;
//             dfs(u);
//             for(int i=0;i<n;++i) if(!flag[i]) {
//                 bridge.insert({b1, b2});
//             }
//         }
//     }

//     while(q--) {
//         int s, t; cin >> s >> t;
        
//         for(int i=0;i<n;++i) flag[i] = false;
//         for(int i=0;i<n;++i) dist[i] = INT_MAX;
//         priority_queue<pii, vector<pii>, greater<pii>> pq;
//         dist[s] = 0;
//         pq.emplace(dist[s], s);
//         while(!pq.empty()) {
//             auto [d, u] = pq.top();
//             pq.pop();

//             if(flag[u]) continue;
//             flag[u] = true;

//             for(auto [v, w]: adj[u]) {
//                 if(bridge.find({u, v}) != bridge.end()) continue;

//                 if(dist[v] > d + w) {
//                     dist[v] = d + w;
//                     pq.emplace(dist[v], v);
//                 }
//             }
//         }

//         cout << (dist[t] == INT_MAX ? -1 : dist[t]) << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>

#define int long long
#define INT_MAX 1e18

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;
int cnt = 0;
vector<pii> adj[N];
bool flag[N];
int dist[N], num[N], mn[N];
set<pii> bridge;

void tarjan(int u, int prev) {
    flag[u] = true;

    mn[u] = num[u] = ++cnt;
    int child = 0;
    for(auto [v, w]: adj[u]) {
        if(!flag[v]) {
            ++child;
            tarjan(v, u);
            mn[u] = min(mn[u], mn[v]);
            if(mn[v] > num[u]) {
                bridge.insert({u, v});
            }
        } else if(v != prev) {
            mn[u] = min(mn[u], num[v]);
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q; cin >> n >> m >> q;
    for(int i=0;i<m;++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    tarjan(0, -1);

    while(q--) {
        int s, t; cin >> s >> t;
        
        for(int i=0;i<n;++i) flag[i] = false;
        for(int i=0;i<n;++i) dist[i] = INT_MAX;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[s] = 0;
        pq.emplace(dist[s], s);
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(flag[u]) continue;
            flag[u] = true;

            for(auto [v, w]: adj[u]) {
                if(bridge.find({u, v}) != bridge.end()) continue;
                // if(bridge.find({v, u}) != bridge.end()) continue;

                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        cout << (dist[t] == INT_MAX ? -1 : dist[t]) << '\n';
    }

    return 0;
}