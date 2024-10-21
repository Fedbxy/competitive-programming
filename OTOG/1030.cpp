#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    int a[n][m];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

    ll sum = 0, cnt = 0;
    while(q--) {
        int ui, uj; cin >> ui >> uj;
        char c; cin >> c;
        int di, dj;
        if (c == 'U') di = -1, dj = 0;
        else if (c == 'D') di = 1, dj = 0;
        else if (c == 'L') di = 0, dj = -1;
        else if (c == 'R') di = 0, dj = 1;
        else di = 0, dj = 0;
        int vi = ui + di, vj = uj + dj;
        if (vi >= 0 and vi < n and vj >= 0 and vj < m) sum += a[vi][vj];
        else ++cnt;
    }
    cout << sum << ' ' << cnt;
    return 0;
}