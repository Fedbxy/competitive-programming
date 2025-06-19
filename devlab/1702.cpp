#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b; cin >> a >> b;
    int ans = 1;
    for (int i = 0; i < b; ++i) ans *= a;
    cout << ans << '\n';
    return 0;
}