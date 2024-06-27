#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10;
int a[N];
vector<int> adj[N];
int dist[N];
bool flag[N];
int mxdist;
int mx[N];
int mn[N];
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, s, q; cin >> n >> m >> s >> q;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for(int i=0;i<m;++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> que;
    flag[s] = true;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
 
        for(auto v: adj[u]) {
            if(flag[v]) continue;
            flag[v] = true;
            dist[v] = dist[u] + 1;
            mxdist = max(mxdist, dist[v]);
            que.push(v);
        }
    }
 
    for(int i=1;i<=n;++i) {
        mx[dist[i]] = max(mx[dist[i]], a[i]);
    }
 
    int total = 0;
    mn[0] = INT_MAX;
    for(int i=1;i<=mxdist;++i) {
        total += mx[i];
        mn[i] = min(mn[i-1], mx[i]);
    }
 
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int x, y; cin >> x >> y;
            int disty = dist[x] + 1;
            if(disty <= mxdist) {
                int temp = max(mn[disty], y);
                cout << total - mn[disty] + temp << '\n';
            } else {
                cout << total + y << '\n';
            }
        } else {
            int y; cin >> y;
        }
    }
    return 0;
}