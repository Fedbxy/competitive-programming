#include <bits/stdc++.h>

using namespace std;

int n, l, r;
const int N = 2e8 + 10;
int dp[N];
bool flag[N];

int recur(int x) {
    if(x < l + r) return 0;
    if(flag[x]) return dp[x];
    flag[x] = true;
    return dp[x] = recur(x * l / (l+r)) + recur(x * r / (l+r)) + 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> l >> r;
    cout << recur(n) + 1 << '\n';
    return 0;
}