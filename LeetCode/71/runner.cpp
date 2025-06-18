#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;

    Solution sol;
    cout << sol.simplifyPath(s) << '\n'; 
    return 0;
}