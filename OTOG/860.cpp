#include <bits/stdc++.h>

using namespace std;
using pic = pair<int, char>;

const int N = 155, L = 2505;
const int md = 1e9 + 7;
int n, m, start, l;
string s;
vector<pic> adj[N];
int dp[N][L];
bool flag[N][L];

int dfs(int u, int idx) {
    if(idx == l) return 1;
    if(flag[u][idx]) return dp[u][idx];
    flag[u][idx] = true;

    int res = 0;
    for(auto [v, c]: adj[u]) if(s[idx] == c) res = (res + dfs(v, idx + 1)) % md;

    return dp[u][idx] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        char c; cin >> c;
        adj[u].emplace_back(v, c);
    }
    cin >> start >> l >> s;

    cout << dfs(start, 0) << '\n';
    return 0;
}