#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int l = 0, r = n - 1, ans = 0;
    while(l < r) {
        ans = max(ans, min(a[l], a[r]) * (r - l));
        if(a[l] > a[r]) r--;
        else l++;
    }
    cout << ans << '\n';
    return 0;
}