#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int n, m;
char a[N][N];
int ans;
bool flag[N][N];

const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

void dfs(int i, int j, int sum) {
    if(sum < 0) return;
    if(a[i][j] == 'E') {
        ans = max(ans, sum);
        return;
    }

    if(a[i][j] == '*') sum++;
    else sum--;

    for(int k=0;k<4;k++) {
        int vi = i + di[k], vj = j + dj[k];
        if(vi >= 0 and vi < n and vj >= 0 and vj < m) {
            if(!flag[vi][vj]) {
                flag[vi][vj] = true;
                dfs(vi, vj, sum);
                flag[vi][vj] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
    dfs(0, 0, 3);
    cout << ans + 1 << '\n';
    return 0;
}

/*
5 5
S * * * *
X X X X *
* * * * *
* X X X X
* * X * E

5 5
S X X * *
* * X * *
* * X * *
* * X * *
* * * * E
*/