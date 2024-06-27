#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    
    if(n <= 3) {
        cout << 0 << '\n';
        return 0;
    }

    if(n == 4) {
        cout << (k == 1) << '\n';
        return 0;
    }

    return 0;
}