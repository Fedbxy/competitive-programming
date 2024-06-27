#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pip = pair<int, pair<ll, int>>;

map<pip, int> dp;
const int md = 5454541;

int recur(vector<int> &arr, int idx, ll sum, int cnt) {
    if(idx == 0) {
        return 0;
    }
    if(dp.find({idx, {sum, cnt}}) != dp.end()) return dp[{idx, {sum, cnt}}];

    int res = recur(arr, idx-1, sum, cnt);
    res = (res + recur(arr, idx-1, sum + arr[idx], cnt+1)) % md;
    if((sum + arr[idx]) % (cnt+1) == 0) res = (res + 1) % md;

    return dp[{idx, {sum, cnt}}] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;++i) cin >> arr[i];

    cout << recur(arr, n, 0, 0) << '\n';
    return 0;
}