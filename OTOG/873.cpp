#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int fenwick[N];
int a[N];

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
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];

    for(int i=1;i<=n;++i) {
        cout << query(a[i]) << ' ';
        update(a[i], 1);
    }
    cout << '\n';
    return 0;
}