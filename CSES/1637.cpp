// NO DP

// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int n; cin >> n;
//     int ans = 0;
//     while(n != 0) {
//         string s = to_string(n);
//         int mx = INT_MIN;
//         for(auto e:s) mx = max(mx, e - '0');
//         n -= mx;
//         ans++;
//     }
//     cout << ans << '\n';
//     return 0;
// }

// DP

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=0;i<=n;i++) {
        string s = to_string(i);
        for(auto e:s) {
            int d = e - '0';
            if(i - d >= 0) dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}