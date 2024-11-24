#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s.insert(x);
    }

    while (q--) {
        int x; cin >> x;
        auto itr = s.upper_bound(x);

        if (itr == s.begin()) {
            cout << -1 << '\n';
            continue;
        }

        cout << *--itr << '\n';
        s.erase(itr);
    }
    return 0;
}