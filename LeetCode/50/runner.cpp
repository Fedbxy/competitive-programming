#include <bits/stdc++.h>

using namespace std;

#include "sol.cpp"

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    double x;
    int n;
    cin >> x >> n;

    Solution sol;
    cout << sol.myPow(x, n) << '\n'; 
    return 0;
}