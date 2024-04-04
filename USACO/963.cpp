#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n; cin >> k >> n;
    vector<vector<int>> a(k, vector<int> (n));
    for(auto &i:a) for(auto &j:i) cin >> j;

    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            bool valid = true;
            int first = 0;
            for(int session=0;session<k;session++) {
                for(int idx=0;idx<n;idx++) {
                    if(a[session][idx] == i or a[session][idx] == j) {
                        if(!first) first = a[session][idx];
                        else if(a[session][idx] != first) valid = false;
                        break;
                    }
                }
            }
            if(valid) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}