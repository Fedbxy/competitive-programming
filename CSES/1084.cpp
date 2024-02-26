#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    while(i != n and j != m) {
        if(abs(a[i] - b[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if(a[i] > b[j]) j++;
        else i++;
    }
    cout << ans <<'\n';
    return 0;
}