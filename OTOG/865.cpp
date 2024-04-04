#include <bits/stdc++.h>

#define int long long

using namespace std;
using pii = pair<int, int>;

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<pii> pos(k);
    for(int i=0;i<k;i++) cin >> pos[i].first >> pos[i].second;

    int cnt = 0, day = 0, prevcnt = 0;
    vector<int> total;
    vector<vector<bool>> flag(n, vector<bool>(m));
    vector<pii> next_que;
    while(cnt < n * m or day < k) {
        queue<pii> que;
        for(auto e: next_que) que.push(e);
        next_que.clear();
        int sum = (day > 0 ? total[day-1] : 0), newcnt = 0;
        while(!que.empty()) {
            auto [ui, uj] = que.front();
            que.pop();

            for(int i=0;i<4;i++) {
                int vi = ui + di[i], vj = uj + dj[i];
                if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) {
                    flag[vi][vj] = true;
                    newcnt++;
                    next_que.emplace_back(vi, vj);
                }
            }
        }

        if(day < k) {
            auto [i, j] = pos[day];
            if(!flag[i][j]) flag[i][j] = true, newcnt++, next_que.emplace_back(i, j);
            else sum++;
        }
        day++;

        // cout << "#" << day << ' '  << cnt << '\n';
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout << flag[i][j];
        //     }
        //     cout << '\n';
        // }
        // cout << "TOTAL: " << newcnt << " + " << prevcnt << " + " << sum << " = " << newcnt + prevcnt + sum << '\n';

        total.push_back(newcnt + prevcnt + sum);
        cnt += newcnt;
        prevcnt = cnt;
    }
    
    // for(auto e:total) cout << e << ' ';
    // cout << '\n';

    while(q--) {
        int x; cin >> x;
        if(x <= total.size()) cout << total[x-1] << '\n';
        else cout << total[total.size()-1] + n * m * (x - total.size()) << '\n';
    }
    return 0;
}