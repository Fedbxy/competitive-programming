#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, x; cin >> n >> m;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];
    while(m--) cin >> x, cout << upper_bound(a.begin(), a.end(), x) - a.begin() - 1 << '\n';
    return 0;
}