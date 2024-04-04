#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const int N = 5e4 + 10;
int n, m;
string s, t;
ll g;
vector<int> a, a_sort;
vector<pii> adj[N];
unordered_map<string, int> idx;
bool flag[N];
ll dist[N];
ll ans = 1e18;

void dijkstra(int s) {
    for(int i=0;i<n;i++) dist[i] = 1e18;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto [v, w]: adj[u]) {
            if(!flag[v] and dist[v] > d + w) dist[v] = d + w, pq.push({dist[v], v});
        }
    }
}

bool ok(int x) {
    for(int i=0;i<n;i++) if(a[i] > x) flag[i] = true; else flag[i] = false;
    dijkstra(idx[s]);
    if(dist[idx[t]] <= g) ans = dist[idx[t]];
    return dist[idx[t]] <= g;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n);
    a_sort.resize(n);
    cin >> s >> t >> g;
    for(int i=0;i<n;i++) {
        string p; int x; cin >> p >> x;
        idx[p] = i;
        a[i] = a_sort[i] = x;
    }
    for(int i=0;i<m;i++) {
        string u, v;
        ll w; cin >> u >> v >> w;
        adj[idx[u]].push_back({idx[v], w});
        adj[idx[v]].push_back({idx[u], w});
    }

    sort(a_sort.begin(), a_sort.end());
    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(ok(a_sort[mid])) r = mid;
        else l = mid + 1;
    }
    cout << a_sort[r] << ' ' << ans << '\n';
    return 0;
}