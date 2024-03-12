#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool flag[N];

void dijkstra(int s) {
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v:adj[u]) {
            if(flag[v]) continue;
            flag[v] = true;
            q.push(v);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    for(int i=1;i<=n;i++) if(!flag[i]) dijkstra(i), ans.push_back(i);
    cout << ans.size() - 1 << '\n';
    for(int i=1;i<ans.size();i++) {
        cout << ans[0] << ' ' << ans[i] << '\n';
    }
    return 0;
}