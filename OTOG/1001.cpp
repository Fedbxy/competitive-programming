#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int fenwick[N];

void update(int i, int val) {
    while(i < N) {
        fenwick[i] += val;
        i += i & (-i);
    }
}

int query(int i) {
    int res = 0;
    while(i > 0) {
        res += fenwick[i];
        i -= i & (-i);
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> m >> n;
    for(int i=0;i<m;++i) {
        int t; cin >> t;
        if(t == 1) {
            int l, r; cin >> l >> r;
            update(l, 1);
            update(r+1, -1);
        } else {
            int x; cin >> x;
            cout << query(x) << '\n';
        }
    }

    for(int i=1;i<=n;++i) cout << query(i) << ' ';
    cout << '\n';

    return 0;
}