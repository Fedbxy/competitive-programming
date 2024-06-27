#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;
bool neighbor[N];
vector<pii> adj[N];
int dist[N];
int ddist[N][20];

int dfs(int u, int parent) {
    if(neighbor[u]) return 0;

    int res = INT_MIN;
    for(auto [v, w]: adj[u]) {
        if(v == parent) continue;
        res = max(res, dfs(v, u) + w);
    }
    return res;
}

void dijkstra(int s, int idx) {
    bool flag[N];
    memset(flag, false, sizeof(flag));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    ddist[s][idx] = 0;
    pq.emplace(ddist[s][idx], s);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) {
            if(flag[v]) continue;
            if(ddist[v][idx] > d + w) {
                ddist[v][idx] = d + w;
                if(!neighbor[v]) pq.emplace(ddist[v][idx], v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q; cin >> n >> q;
    int cnt = 0;
    for(int i=0;i<n;++i) {
        bool x; cin >> x;
        cnt += x;
        neighbor[i] = x;
    }
    for(int i=0;i<n-1;++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    if(cnt <= 20) goto sub4;

    for(int i=0;i<n;++i) {
        dist[i] = dfs(i, -1);
    }

    while(q--) {
        int x; cin >> x;
        cout << dist[x] << '\n';
    }

    return 0;

    sub4:
    for(int i=0;i<N;++i) for(int j=0;j<20;++j) ddist[i][j] = INT_MAX;
    vector<int> sel;
    for(int i=0;i<n;++i) {
        if(neighbor[i]) {
            sel.push_back(i);
        }
    }
    for(int i=0;i<sel.size();++i) dijkstra(sel[i], i);
    while(q--) {
        int x; cin >> x;
        int ans = 0;
        for(int i=0;i<sel.size();++i) if(ddist[x][i] != INT_MAX) ans = max(ans, ddist[x][i]);
        if(neighbor[x]) ans = 0;
        cout << ans << '\n';
    }
    return 0;
}