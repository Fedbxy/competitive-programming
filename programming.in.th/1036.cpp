#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
const int K = 1<<8;
int val[N], bit[N], dp[K];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i=0;i<K;++i) dp[i] = 1e9;

    int n, k; cin >> n >> k;
    for(int i=1;i<=n;++i) {
        cin >> val[i];
        int sum = 0;
        for(int i=0;i<k;++i) {
            int x; cin >> x;
            sum += x << i;
        }
        bit[i] = sum;
    }

    dp[0] = 0;
    for(int i=1;i<=n;++i) {
        for(int mask=0;mask<1<<k;++mask) {
            dp[bit[i]|mask] = min(dp[bit[i]|mask], dp[mask] + val[i]);
        }
    }
    cout << dp[(1<<k)-1] << '\n';
    return 0;
}