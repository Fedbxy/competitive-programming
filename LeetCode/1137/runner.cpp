#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    Solution sol;
    cout << sol.tribonacci(n) << '\n'; 
    return 0;
}