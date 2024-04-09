#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const ll INF = 1e18;
 
vector<ll> a;
int n;
ll totalSum, ans = INF;
 
void recur(int idx, ll sum) {
    if(idx == -1) {
        ans = min(ans, abs((totalSum - sum) - sum));
        return;
    }
 
    recur(idx - 1, sum);
    recur(idx - 1, sum + a[idx]);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for(auto &e: a) cin >> e, totalSum += e;
 
    // recur(n-1, 0);
    // cout << ans << '\n';

    for(int bit = 0; bit < (1 << n); bit++) {
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(bit & (1 << i)) sum += a[i];
        }
        ans = min(ans, abs((totalSum - sum) - sum));
    }
    cout << ans << '\n';
    return 0;
}