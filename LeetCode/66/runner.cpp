#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &e: arr) cin >> e;

    Solution sol;
    vector<int> ans = sol.plusOne(arr);
    for(auto e: ans) cout << e << ' ';
    return 0;
}