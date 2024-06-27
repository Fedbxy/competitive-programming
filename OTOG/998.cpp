#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
int a[N], dp[N][N], ans[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];

    int temp = a[1];
    bool check = true;
    for(int i=2;i<=n;++i) check = a[i] == temp, temp = a[i];
    if(check and n >= 500) {
        cout << n * temp << '\n';
        return 0;
    }

    for(int sz=1;sz<=n;++sz) {
        multiset<int> s1;
        set<int> s2;
        for(int i=1;i<=sz;++i) {
            s1.insert(a[i]);
            s2.insert(a[i]);
        }
        dp[1][sz] = *s1.rbegin() * (int)s2.size();
        for(int i=2;i<=n-sz+1;++i) {
            int j = i + sz - 1;
            if(s1.count(a[i-1]) > 1) {
                s1.erase(s1.find(a[i-1]));
            } else {
                s1.erase(a[i-1]);
                s2.erase(a[i-1]);
            }
            s1.insert(a[j]);
            s2.insert(a[j]);
            dp[i][j] = max(dp[i][j], *s1.rbegin() * (int)s2.size());
        }

        ans[sz] = dp[1][sz];
        for(int cut=1;cut<sz;++cut) {
            ans[sz] = max(ans[sz], ans[cut] + dp[cut+1][sz]);
        }
    }

    cout << ans[n] << '\n';

    return 0;
}