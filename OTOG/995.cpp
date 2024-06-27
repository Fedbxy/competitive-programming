// dijkstra on state
// #include <bits/stdc++.h>

// #define int long long
// #define INT_MAX 1e18

// using namespace std;
// using pii = pair<int, int>;
// using ppi = pair<pii, int>;

// const int N = 2e5 + 10, K = 15;
// vector<pii> adj[N];
// int dist[N][K];
// bool flag[N][K];

// signed main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     for(int i=0;i<N;++i) for(int j=0;j<K;++j) dist[i][j] = INT_MAX;

//     int n, k; cin >> n >> k;
//     for(int i=0;i<n-1;++i) {
//         int a, x, b; cin >> a >> x >> b;
//         adj[i].emplace_back(i+1, a);
//         adj[i].emplace_back(x, b);
//     }

//     priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
//     dist[0][0] = 0;
//     pq.push({{dist[0][0], 0}, 0});
//     while(!pq.empty()) {
//         auto [e, cnt] = pq.top();
//         auto [d, u] = e;
//         pq.pop();

//         if(flag[u][cnt]) continue;
//         flag[u][cnt] = true;
        
//         for(auto [v, w]: adj[u]) {
//             if(v == u + 1 and dist[v][cnt] > dist[u][cnt] + w) {
//                 dist[v][cnt] = dist[u][cnt] + w;
//                 pq.push({{dist[v][cnt], v}, cnt});
//             }

//             if(v != u + 1 and cnt < k and dist[v][cnt+1] > dist[u][cnt] + w) {
//                 dist[v][cnt+1] = dist[u][cnt] + w;
//                 pq.push({{dist[v][cnt+1], v}, cnt+1});
//             }
//         }
//     }

//     int ans = INT_MAX;
//     for(int i=0;i<=k;++i) ans = min(ans, dist[n-1][i]);
//     cout << ans << '\n';
//     return 0;
// }

// dp
#include <bits/stdc++.h>

#define int long long
#define INT_MAX 1e15

using namespace std;
using pii = pair<int, int>;
using pip = pair<int, pii>;

const int N = 2e5 + 10;
const int K = 11;
pip arr[N];
int dp[N][K];

signed main() {
    for(int i=0;i<N;++i) for(int j=0;j<K;++j) dp[i][j] = INT_MAX;

    int n, k;
    scanf("%lld %lld", &n, &k);
    for(int i=0;i<n-1;++i) {
        int a, x, b;
        scanf("%lld %lld %lld", &a, &x, &b);
        arr[i] = {a, {x, b}};
    }

    for(int i=0;i<=k;++i) dp[0][i] = 0;
    for(int j=0;j<=k;++j) {
        for(int i=0;i<n-1;++i) {
            auto [a, e] = arr[i];
            auto [x, b] = e;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a);
            dp[x][j+1] = min(dp[x][j+1], dp[i][j] + b);
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<=k;++i) {
        ans = min(ans, dp[n-1][i]);
    }
    printf("%lld\n", ans);

    return 0;
}