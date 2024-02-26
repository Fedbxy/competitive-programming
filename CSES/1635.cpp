#include <bits/stdc++.h>

using namespace std;

const int md = 1e9+7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int i=0;i<=x;i++) {
        for(int j=0;j<n;j++) {
            if(i - a[j] < 0) continue;
            (dp[i] += dp[i - a[j]]) %= md;
        }
    }
    
    cout << dp[x] << '\n';
    return 0;
}