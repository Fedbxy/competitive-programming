#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};
const string dc = "UDLR";

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    bool flag[n][m]; memset(flag, false, sizeof(flag));
    char dir[n][m]; memset(dir, 'X', sizeof(dir));
    char c;
    pii s, t;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> c;
        if(c == '#') flag[i][j] = true;
        else if(c == 'A') s.first = i, s.second = j;
        else if(c == 'B') t.first = i, t.second = j;
    }

    queue<pii> q;
    q.push(s);
    while(!q.empty()) {
        int ui = q.front().first, uj = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) q.push({vi, vj}), flag[vi][vj] = true, dir[vi][vj] = dc[i];
        }
    }

    if(flag[t.first][t.second]) {
        cout << "YES\n";
        pii cur = t;
        string ans;
        while(cur != s) {
            c = dir[cur.first][cur.second];
            ans.push_back(c);
            for(int i=0;i<4;i++) if(c == dc[i]) cur.first -= di[i], cur.second -= dj[i];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}