#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const vector<int> di = {0, 0, -1, 1};
const vector<int> dj = {-1, 1, 0, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<bool>> flag(n, vector<bool> (m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        char c; cin >> c;
        a[i][j] = c != '.';
        flag[i][j] = c == '.';
    }

    queue<pii> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        const auto [ui, uj] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            const int vi = ui + di[i], vj = uj + dj[i];
            if (vi >= 0 and vi < n and vj >= 0 and vj < m and !a[vi][vj]) {
                a[vi][vj] = 2;
                q.emplace(vi, vj);
            }
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (!flag[i][j]) {
            flag[i][j] = true;
            int sum = 0;
            q.emplace(i, j);
            while (!q.empty()) {
                const auto [ui, uj] = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    const int vi = ui + di[k], vj = uj + dj[k];
                    if (vi >= 0 and vi < n and vj >= 0 and vj < m) {
                        if (!flag[vi][vj]) q.emplace(vi, vj), flag[vi][vj] = true;
                        if (a[vi][vj] == 2) ++sum;
                    }
                }
            }
            mx = max(mx, sum);
        }
    }
    cout << mx << '\n';
    return 0;
}