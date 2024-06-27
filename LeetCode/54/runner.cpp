#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];

    Solution sol;
    for (auto &e: sol.spiralOrder(a)) cout << e << ' ';
    cout << '\n';
    return 0;
}