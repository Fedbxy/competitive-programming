#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    sort(a.begin(), a.end());

    int i = 0, j = n - 1, ans = 0;
    while(i <= j) {
        if(a[i] + a[j] <= x) ans++, i++, j--;
        else ans++, j--;
    }

    cout << ans << '\n';
    return 0;
}