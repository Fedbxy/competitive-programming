#include <bits/stdc++.h>

using namespace std;
#define mp(x, y) make_pair(x, y)
#define int long long
#define INT_MAX LLONG_MAX
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;

const int N = 8e4 + 10, Q = 9;
vector<pii> adj[N];
bool room[N];
int dist[N][Q];

signed main() {
    for(int i=0;i<N;++i) for(int j=0;j<Q;++j) dist[i][j] = INT_MAX;

    int n, m, l, q;
    scanf("%lld %lld %lld %lld", &n, &m, &l, &q);
    for(int i=0;i<m;++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].emplace_back(v, w);
    }
    for(int i=0;i<l;++i) {
        int x;
        scanf("%lld", &x);
        room[x] = true;
    }

    priority_queue<ppp, vector<ppp>, greater<ppp>> pq;
    dist[1][0] = 0;
    pq.emplace(mp(dist[1][0], 1), mp(0, -1));
    while(!pq.empty()) {
        auto [e1, e2] = pq.top();
        auto [d, u] = e1;
        auto [cnt, prev] = e2;
        pq.pop();

        for(auto [v, w]: adj[u]) {
            if(dist[v][cnt] > d + (w >> cnt)) {
                dist[v][cnt] = d + (w >> cnt);
                pq.emplace(mp(dist[v][cnt], v), mp(cnt, prev));
            }

            if(room[u] and u != prev and cnt < q and dist[v][cnt+1] > d + (w >> (cnt + 1))) {
                dist[v][cnt+1] = d + (w >> (cnt + 1));
                pq.emplace(mp(dist[v][cnt+1], v), mp(cnt+1, u));
            }
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<=q;++i) ans = min(ans, dist[n][i]);
    printf("%lld", ans);

    return 0;
}