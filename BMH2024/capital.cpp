// written by poom
// score: 30/30

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MxN = 1e4 + 1;
int n, x, y, z;

vector<pll> adj[MxN];

ll dfs(int u, int p) {
    ll total = 0;
    
    for (pll k : adj[u]) {
        int v = k.first;
        int w = k.second;

        if (v != p) {
            total = max(total, dfs(v, u) + w);
        }
    }

    return total;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }

    cout << dfs(1, -1);
}