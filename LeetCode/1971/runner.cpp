#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> edges;
    while(m--) {
        int a, b; cin >> a >> b;
        edges.push_back({a, b});
    }
    int s, t; cin >> s >> t;

    Solution sol;
    cout << sol.validPath(n, edges, s, t) << '\n'; 
    return 0;
}