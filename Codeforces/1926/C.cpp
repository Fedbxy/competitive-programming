#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int dp[200001];
    dp[0] = 0;
    for(int i=1;i<=200000;i++) {
        int sum = 0;
        string s = to_string(i);
        for(auto e:s) sum += e - '0';
        dp[i] = dp[i-1] + sum;
    }
    int t;cin>>t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}