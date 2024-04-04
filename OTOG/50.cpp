#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int n, si, sj;

int a[N][N];
bool flag[N][N];
bool dp[N][N];
bool dped[N][N];

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

bool dfs(int ui, int uj, int mx) {
    if(ui != si and uj != sj and a[ui][uj] == 0) return true;
    if(a[ui][uj] > mx) return false;
    if(dped[ui][uj]) return dp[ui][uj];
    dped[ui][uj] = true;

    bool res = false;
    for(int i=0;i<4;i++) {
        int vi = ui + di[i], vj = uj + dj[i];
        if(vi > 0 and vi <= n and vj > 0 and vj <= n and !flag[vi][vj]) {
            flag[vi][vj] = true;
            if(dfs(vi, vj, mx)) res = true;
            flag[vi][vj] = false;
        }
    }
    return dp[ui][uj] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    int l = INT_MAX, r = INT_MIN;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        cin >> a[i][j];
        if(a[i][j] == 0) si = i, sj = j;
        l = min(l, a[i][j]);
        r = max(r, a[i][j] + 1);
    }

    while(l < r) {
        memset(dped, false, sizeof(dped));
        memset(dp, 0, sizeof(dp));
        int mid = l + (r - l) / 2;
        if(dfs(si, sj, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}