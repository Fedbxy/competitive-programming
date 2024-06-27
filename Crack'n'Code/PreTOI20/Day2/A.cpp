#include <bits/stdc++.h>

#define int long long
#define INT_MAX LLONG_MAX

using namespace std;
using pii = pair<int, int>;
using pip = pair<int, pii>;

const int N = 1e3 + 10;
int a[N][N];
int dist[N][N];
bool flag[N][N];

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<N;++i) for(int j=0;j<N;++j) dist[i][j] = INT_MAX;

    int n, m, ci, cj; cin >> n >> m >> ci >> cj;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cin >> a[i][j];
        }
    }

    priority_queue<pip, vector<pip>, greater<pip>> pq;
    dist[ci][cj] = 0;
    pq.push({dist[ci][cj], {ci, cj}});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        auto [ui, uj] = u;
        pq.pop();

        if(flag[ui][uj]) continue;
        flag[ui][uj] = true;

        for(int i=0;i<4;++i) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi > 0 and vi <= n and vj > 0 and vj <= m and !flag[vi][vj]) {
                if(dist[vi][vj] > d + a[vi][vj]) {
                    dist[vi][vj] = d + a[vi][vj];
                    pq.push({dist[vi][vj], {vi, vj}});
                }
            }
        }
    }

    int mn = INT_MAX;
    const int ei[] = {1, n, 1, n};
    const int ej[] = {1, 1, m, m};
    for(int i=0;i<4;++i) {
        mn = min(mn, dist[ei[i]][ej[i]]);
    }
    
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cout << dist[i][j] + a[ci][cj] + mn << ' ';
        }
        cout << '\n';
    }
    return 0;
}