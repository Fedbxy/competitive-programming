#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int a[N][N];
int ps[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int k; cin >> k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i-1][j-1];

    int ans = INT_MIN;
    for(int i=1;i<=n-k+1;i++) for(int j=1;j<=m-k+1;j++) ans = max(ans, ps[i+k-1][j+k-1] - ps[i+k-1][j-1] - ps[i-1][j+k-1] + ps[i-1][j-1]);
    cout << ans << '\n';
    return 0;
}