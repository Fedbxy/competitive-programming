#include <bits/stdc++.h>

using namespace std;

struct Mountain {
    int l, r, idx;
};

bool cmp(const Mountain &l, const Mountain &r) {
    if(l.l == r.l) return l.r < r.r;
    return l.l > r.l;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<Mountain> arr(n);
    for(int i=0;i<n;++i) {
        cin >> arr[i].l >> arr[i].r;
        arr[i].idx = i;
    }
    sort(arr.begin(), arr.end(), cmp);
    
    vector<int> dp(n), mn(n+1);
    int len = 1;
    dp[0] = 1;
    mn[1] = arr[0].r;
    for(int i=1;i<n;++i) {
        if(arr[i].r >= mn[len]) {
            dp[i] = ++len;
            mn[len] = arr[i].r;
        } else {
            int p = upper_bound(mn.begin() + 1, mn.begin() + len + 1, arr[i].r) - mn.begin();
            dp[i] = p;
            mn[p] = arr[i].r;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    vector<int> ans(n);
    for(int i=0;i<n;++i) ans[arr[i].idx] = dp[i];
    for(auto e: ans) cout << e << ' ';
    cout << '\n';
    return 0;
}