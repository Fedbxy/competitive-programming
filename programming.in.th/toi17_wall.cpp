#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int a[n][m];
     bool flag[n][m];
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            char c; cin >> c;
            a[i][j] = c != '.';
            flag[i][j] = c == '.';
        }
    }

    queue<pii> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [ui, uj] = q.front();
        q.pop();

        for(int i=0;i<4;++i) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj >=0 and vj < m and !a[vi][vj]) {
                a[vi][vj] = 2;
                q.push({vi, vj});
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
        if(!flag[i][j]) {
            q.push({i, j});
            flag[i][j] = true;
            int sum = 0;
            while(!q.empty()) {
                auto [ui, uj] = q.front();
                q.pop();

                for(int i=0;i<4;++i) {
                    int vi = ui + di[i], vj = uj + dj[i];
                    if(vi >= 0 and vi < n and vj >=0 and vj < m) {
                        if(!flag[vi][vj]) q.push({vi, vj}), flag[vi][vj] = true;
                        if(a[vi][vj] == 2) ++sum;
                    }
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
4 6
......
.X.X..
.X.XX.
......

4 6
......
.X.X..
..X.X.
......

5 5
.....
..X..
.X.X.
..X..
.....

7 6
......
.X.X..
.X.X..
.X..X.
.X..X.
.XXXX.
......

8 7
.......
.XXXXX.
.X...X.
.X.X.X.
.X.X.X.
.X...X.
.XXXXX.
.......
*/