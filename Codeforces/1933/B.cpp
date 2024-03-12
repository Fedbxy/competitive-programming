#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0, ans = 3;
    for(int i=0;i<n;i++) cin >> a[i], sum += a[i];
    if(sum % 3 == 0) ans = 0;
    for(int i=1;i<=2;i++) if((sum + i) % 3 == 0) ans = min(ans, i);
    for(int i=0;i<n;i++) if((sum - a[i]) % 3 ==0) ans = min(ans, 1);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}