#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        ++m[l];
        --m[r + 1];
    }
    
    int sum = 0, mx = INT_MIN;
    for (auto& e: m) sum += e.second, mx = max(mx, sum);
    cout << mx << '\n';
    return 0;
}