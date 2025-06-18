#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 110;
char a[N][N];
bool flag[N][N];
int k, n, m, q, x, cnt, tmp, idx;
vector<int> mx;
queue<pii> que;

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> k >> n >> m;
    mx.resize(k);
    for (int f = 0; f < k; ++f) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            flag[i][j] = a[i][j] == '#';
        }

        tmp = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (not flag[i][j]) {
                cnt = a[i][j] == 'X';
                flag[i][j] = true;
                que.emplace(i, j);
                while (not que.empty()) {
                    const auto [ui, uj] = que.front();
                    que.pop();
    
                    for (int d = 0; d < 4; ++d) {
                        const int vi = ui + di[d], vj = uj + dj[d];
                        if (vi >= 0 and vi < n and vj >= 0 and vj < m and not flag[vi][vj]) {
                            cnt += a[vi][vj] == 'X';
                            flag[vi][vj] = true;
                            que.emplace(vi, vj);
                        }
                    }
                }
    
                tmp = max(tmp, cnt);
            }
        }

        mx[f] = tmp;
    }

    sort(mx.begin(), mx.end(), greater<int>());
    for (int i = 1; i < k; ++i) mx[i] += mx[i-1];

    cin >> q;
    while (q--) {
        cin >> x;
        idx = lower_bound(mx.begin(), mx.end(), x) - mx.begin();
        cout << (idx == k ? -1 : idx + 1) << '\n';
    }

    return 0;
}