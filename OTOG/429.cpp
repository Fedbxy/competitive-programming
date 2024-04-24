#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int dp[510][30][30];
bool flag[510][30][30];

int recur(int idx, int paint1, int paint2) {
    if(idx == 0) {
        return 0;
    }
    if(flag[idx][paint1][paint2]) return dp[idx][paint1][paint2];
    flag[idx][paint1][paint2] = true;

    int res = INT_MAX;
    if(paint1 == arr[idx] or paint2 == arr[idx]) {
        res = min(res, recur(idx-1, arr[idx], paint2));
        res = min(res, recur(idx-1, paint1, arr[idx]));
    } else {
        res = min(res, recur(idx-1, arr[idx], paint2) + 1);
        res = min(res, recur(idx-1, paint1, arr[idx]) + 1);
    }
    
    return dp[idx][paint1][paint2] = res;
}

void solve() {
    memset(flag, false, sizeof(flag));
    int n; cin >> n;
    arr.resize(n+1);
    for(int i=1;i<=n;++i) cin >> arr[i];
    
    cout << recur(n, -1, -1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}