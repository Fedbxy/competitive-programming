#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        int idx = lower_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        ans = max(ans, (a[idx] == a[i] + k ? idx - i : idx - i - 1));
    }
    cout << ans << '\n';
    return 0;
}