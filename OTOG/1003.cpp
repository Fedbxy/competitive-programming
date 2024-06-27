#include <bits/stdc++.h>

#define int long long

using namespace std;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int md = 1e9 + 7;
int fac[N];
map<int, vector<int>> pos;

int inv(int a) {
    return a <= 1 ? a : md - (md / a) * inv(md % a) % md;
}

int cnr(int n, int r) {
    return (fac[n] * inv((fac[r] * fac[n - r]) % md)) % md;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    fac[0] = 1;
    for(int i=1;i<N;++i) fac[i] = (i * fac[i-1]) % md;

    int n, k, q; cin >> n >> k >> q;
    for(int i=1;i<=n;++i) {
        int x; cin >> x;
        pos[x].push_back(i);
    }

    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        ++l, ++r;
        int posr = upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin();
        int posl = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin() + 1;
        int cnt = posr - posl + 1;
        cout << (cnt < k ? -1 : cnr(cnt, k)) << '\n';
    }
    return 0;
}