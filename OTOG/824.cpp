#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e: a) cin >> e;

    vector<int> dp(n), mn(n+1);
    vector<vector<pii>> mnArray(n+1);
    int len = 1;
    dp[0] = 1;
    mn[1] = a[0];
    mnArray[1].push_back({a[0], 0});
    for(int i=1;i<n;++i) {
        if(a[i] > mn[len]) {
            dp[i] = ++len;
            mn[len] = a[i];
            mnArray[len].push_back({a[i], i});
        } else {
            int p = lower_bound(mn.begin() + 1, mn.begin() + len + 1, a[i]) - mn.begin();
            dp[i] = p;
            mn[p] = a[i];
            mnArray[p].push_back({a[i], i});
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;++i) ans = max(ans, dp[i]);
    cout << ans << "     " << '\n';

    vector<int> ansArray;
    ansArray.push_back(mnArray[len].back().first);
    int lastIdx = mnArray[len].back().second;
    for(int i=n-1;i>0;--i) {
        while(!mnArray[i].empty()) {
            int val = mnArray[i].back().first;
            int idx = mnArray[i].back().second;
            // cout << "{" << val << ", " << idx << "} ";
            bool valid = false;
            if(idx < lastIdx) {
                ansArray.push_back(val);
                lastIdx = mnArray[i].back().second;
                valid = true;
            }
            mnArray[i].pop_back();
            if(valid) break;
        }
        // cout << '\n';
    }

    reverse(ansArray.begin(), ansArray.end());
    for(auto e: ansArray) cout << e << ' ';
    cout << '\n';
    return 0;
}

/*
10
2 4 1 2 5 6 3 9 10 1
*/