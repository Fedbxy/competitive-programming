#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int BIT = 18;
vector<int> adj[N];
int parent[N][BIT];

void dfs(int u, int prev) {
    for(auto v: adj[u]) {
        if(v == prev) continue;
        parent[v][0] = u;
        for(int i=1;i<BIT;++i) {
            parent[v][i] = parent[parent[v][i-1]][i-1];
        }
        dfs(v, u);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for(int i=2;i<=n;++i) {
        int p; cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, -1);

    while(q--) {
        int x, k; cin >> x >> k;
        int p = x;
        for(int i=BIT-1;i>=0;--i) {
            if((1 << i) <= k) {
                p = parent[p][i];
                k -= (1 << i);
            }
        }
        cout << (p == 0 ? -1 : p) << '\n';
    }
    return 0;
}