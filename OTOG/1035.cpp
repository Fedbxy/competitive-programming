#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; scanf("%d", &n);
    char s[n + 1]; scanf("%s", s);
    int m; scanf("%d", &m);
    vector<ll> a(26);
    for (int i = 0; i < m; ++i) {
        char c; scanf(" %c", &c);
        scanf("%lld", &a[c - 'A']);
    }
    int r; scanf("%d", &r);

    ll ans = LLONG_MIN;
    vector<int> cnt(26);
    for (int i = 0; i < r; ++i) ++cnt[s[i] - 'A'];
    for (int i = 0; i < n - r + 1; ++i) {
        if (i) {
            --cnt[s[i - 1] - 'A'];
            ++cnt[s[i + r - 1] - 'A'];
        }
        ll sum = 0;
        int mx = INT_MIN, mxIdx, mxCnt = 1;
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

    printf("%lld", ans);
    return 0;
}