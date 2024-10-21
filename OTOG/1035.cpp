#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INT_MIN LLONG_MIN

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    vector<int> a(26);
    for (int i = 0; i < m; ++i) {
        char c; cin >> c;
        int x; cin >> x;
        a[c - 'A'] = x;
    }
    int r; cin >> r;

    int ans = INT_MIN;
    vector<int> cnt(26);
    for (int i = 0; i < r; ++i) ++cnt[s[i] - 'A'];
    for (int i = 0; i < n - r + 1; ++i) {
        if (i) {
            --cnt[s[i - 1] - 'A'];
            ++cnt[s[i + r - 1] - 'A'];
        }
        int sum = 0, mx = INT_MIN, mxIdx, mxCnt = 1;
        for (int j = 0; j < 26; ++j) {
            sum += a[j] * cnt[j];
            if (cnt[j] > mx) {
                mx = cnt[j];
                mxIdx = j;
                mxCnt = 1;
            } else if (cnt[j] == mx) ++mxCnt;
        }
        ans = max(ans, sum - (mxCnt == 1 ? a[mxIdx] * cnt[mxIdx] : 0));
    }

    cout << ans;
    return 0;
}