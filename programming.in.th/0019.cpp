#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int ans = INT_MAX;

void recur(vector<pii> &a, int idx, int s, int b) {
    if(idx == a.size()) {
        if(s == 1 and b == 0) return;
        ans = min(ans, abs(s - b));
        return;
    }

    recur(a, idx + 1, s, b);
    recur(a, idx + 1, s * a[idx].first, b + a[idx].second);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
    recur(a, 0, 1, 0);
    cout << ans << '\n';
    return 0;
}