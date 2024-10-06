#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c; cin >> a >> b >> c;
    
    int n = 1;
    while (true) {
        long long lhs = pow(a, n) + pow(b, n);
        long long rhs = pow(c, n);
        if (lhs == rhs) {
            cout << n;
            return 0;
        }

        if (lhs < rhs) {
            cout << "NO";
            return 0;
        }

        ++n;
    }
    return 0;
}