#include <bits/stdc++.h>

using namespace std;

int func(int n) {
    return n == 1 ? 7 : n == 2 ? -2 : n == 3 ? -2 : func(n - 2) * 3 + func(n - 3) * 4;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    cout << func(n);
    return 0;
}