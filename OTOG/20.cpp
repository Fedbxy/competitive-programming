#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> m >> n;
    int si, sj; cin >> sj >> si;
    char a[n][m];
    bool flag[n][m];
    memset(flag, false, sizeof(flag));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> a[i][j];
        if(a[i][j] == '1') flag[i][j] = true;
    }

    queue<pair<pii, int>> q;
    q.push({{si, sj}, 0});
    queue<pair<char, int>> ans;
    while(!q.empty()) {
        auto [u, cnt] = q.front();
        auto [ui, uj] = u;
        q.pop();

        if(a[ui][uj] >= 'A' and a[ui][uj] <= 'Z') ans.push({a[ui][uj], cnt});

        for(int i=0;i<4;i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) flag[vi][vj] = true, q.push({{vi, vj}, cnt+1}); 
        }
    }

    int prev = ans.front().second;
    vector<char> ans2;
    while(!ans.empty()) {
        auto [c, cnt] = ans.front();
        ans.pop();
        if(cnt != prev) break;
        ans2.push_back(c);
        prev = cnt;
    }
    sort(ans2.begin(), ans2.end());
    for(auto e:ans2) cout << e << '\n';
    return 0;
}