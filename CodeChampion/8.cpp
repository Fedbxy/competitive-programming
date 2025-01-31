#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> adj1[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj1[u].emplace_back(v);
        adj1[v].emplace_back(u);
    }
    cin >> n >> m;
    vector<int> adj2[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj2[u].emplace_back(v);
        adj2[v].emplace_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        sort(adj1[u].begin(), adj1[u].end());
        sort(adj2[u].begin(), adj2[u].end());

        if (adj1[u].size() != adj2[u].size()) {
            cout << "DIFF\n";
            return 0;
        }
        for (int i = 0; i < adj1[u].size(); ++i) {
            if (adj1[u][i] != adj2[u][i]) {
                cout << "DIFF\n";
                return 0;
            }
        }
    }
    cout << "SAME\n";
    return 0;
}