#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> y[i];

    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ans = max(ans, abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
        }
    }
    cout << ans << '\n';
    return 0;
}