#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());
    int ans = accumulate(a.begin(), a.end(), 0);
    int l = 0, r = n - 1;
    while(r - l >= 3) ans -= a[r-1], r -= 2, l += 2;
    cout << ans << '\n';
    return 0;
}