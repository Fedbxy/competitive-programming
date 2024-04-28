#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> strs(n);
    for(auto &e: strs) cin >> e;

    Solution sol;
    cout << sol.longestCommonPrefix(strs) << '\n'; 
    return 0;
}