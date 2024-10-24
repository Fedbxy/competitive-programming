#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, q; scanf("%d %d", &n, &q);
    vector<ll> a(n);
    for (auto &e: a) scanf("%d", &e);

    vector<ll> ps(n+1);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i - 1] * (i % 2 ? 1 : -1);

    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%lld\n", (ps[r] - ps[l - 1]) * (l % 2 ? 1 : -1));
    }
    return 0;
}