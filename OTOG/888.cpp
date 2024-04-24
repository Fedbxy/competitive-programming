#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;
const int N = 1e5 + 10;
int dp[N];

int countWays(int k, int n, vector<int> arr) {
    dp[0] = 1;
    for(int i=1;i<=k;++i) {
        for(auto e: arr) {
            if(i >= e) dp[i] = (dp[i] + dp[i-e]) % md;
        }
    }
    return dp[k];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << countWays(5, 2, {1, 2}) << '\n';
    return 0;
}