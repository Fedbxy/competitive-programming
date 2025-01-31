#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pii> in[n + 1], out[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        in[v].emplace_back(make_pair(u, w));
        out[u].emplace_back(make_pair(v, w));
    }

    for (int u = 1; u <= n; ++u) {
        cout << u << ": ";
        cout << in[u].size() << ' ';
        cout << out[u].size() << ' ';
        int sum = 0;
        for (auto& v: out[u]) sum += v.second;
        cout << sum << ' ';
        sum = 0;
        for (auto& v: in[u]) sum += v.second;
        cout << sum << '\n';
    }
    return 0;
}