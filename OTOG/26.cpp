#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<set<int>> a(n+1);
    while(q--) {
        int x, y; cin >> x >> y;
        a[x].insert(y);
    }
    for(int i=1;i<=n;i++) cout << i << " " << a[i].size() << '\n';
    return 0;
}