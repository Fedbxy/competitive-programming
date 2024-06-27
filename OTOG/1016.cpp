#include <bits/stdc++.h>

using namespace std;

const int N = 21;
int a[1<<N], dp[1<<N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for(int i=0;i<1<<n;++i) {
        string s; cin >> s;
        int c; cin >> c;
        int sum = 0;
        for(int i=0;i<n;++i) if(s[i] == '1') sum += 1 << i;
        a[sum] = c;
    }

    for(int mask=1;mask<1<<n;++mask) {
        int mx = INT_MIN;
        for(int i=0;i<n;++i) if(mask & (1 << i)) mx = max(mx, dp[mask ^ (1 << i)]);
        for(int i=1;i<n;++i) if(mask & (1 << (i - 1)) and mask & (1 << i)) mx = max(mx, dp[(mask ^ (1 << (i - 1))) ^ (1 << i)]);
        dp[mask] = mx + a[mask];
    }

    while(q--) {
        string s; cin >> s;
        int sum = 0;
        for(int i=0;i<n;++i) if(s[i] == '1') sum += 1 << i;
        cout << dp[sum] << '\n';
    }
    return 0;
}