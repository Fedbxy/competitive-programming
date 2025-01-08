#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    deque<int> a(n);
    for (auto& e: a) cin >> e;

    int ans = 0;
    while (m--) {
        char c; cin >> c;
        if (c == 'L') {
            ans += a.front();
            a.pop_front();
        } else {
            ans += a.back();
            a.pop_back();
        }
    }

    cout << ans << '\n';
    return 0;
}