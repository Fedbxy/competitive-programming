#include <bits/stdc++.h>

using namespace std;

void lis(vector<int> &arr, vector<int> &dp, vector<int> &mn) {
    int n = arr.size();
    dp[0] = 1, mn[1] = arr[0];
    int len = 1;
    for(int i=1;i<n;i++) {
        if(arr[i] > mn[len]) {
            len++;
            dp[i] = len;
            mn[len] = arr[i];
        } else {
            int p = lower_bound(mn.begin()+1, mn.begin()+len+1, arr[i]) - mn.begin();
            dp[i] = p;
            mn[p] = arr[i];
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n), b;
    for(int i=0;i<n;i++) cin >> a[i];
    b = a;
    reverse(b.begin(), b.end());

    vector<int> dp1(n), dp2(n), mn1(n+1), mn2(n+1);
    lis(a, dp1, mn1);
    lis(b, dp2, mn2);
    reverse(dp2.begin(), dp2.end());

    while(q--) {
        int x; cin >> x;
        cout << min(dp1[x], dp2[x]) - 1 << '\n';
    }
    return 0;
}