#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<string> name(n + 1);
    for (int i = 1; i <= n; ++i) cin >> name[i];
    vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<bool> flag(n + 1);
    vector<pair<string, int>> ans;
    for (int u = 1; u <= n; ++u) {
        if (!flag[u]) {
            ans.emplace_back(make_pair(name[u], 0));
            queue<int> q;
            q.emplace(u);
            flag[u] = true;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                ++ans[ans.size() - 1].second;

                for (auto& v: adj[u]) {
                    if (flag[v]) continue;
                    flag[v] = true;
                    q.emplace(v);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& e: ans) cout << e.first << ' ' << e.second << '\n';
    return 0;
}