#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<pii> adj[n];
    for(int i=0;i<m;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> dist(n, INT_MAX);
    vector<bool> flag(n);
    priority_queue<int> ans;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0] = 0;
    pq.push({dist[0], 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if(flag[u]) continue;
        flag[u] = true;
        if(d) ans.push(d);

        for(auto [v, w]: adj[u]) if(!flag[v] and dist[v] > w) dist[v] = w, pq.push({dist[v], v});
    }

    while(k--) {
        int temp = ans.top() / 2;
        ans.pop();
        ans.push(temp);
    }

    int sum = 0;
    while(!ans.empty()) {
        sum += ans.top();
        ans.pop();
    }
    cout << sum << '\n';
    return 0;
}