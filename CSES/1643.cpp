#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll sum = a[0], ans = a[0];
    for(int i=1;i<n;i++) {
        sum = max(a[i], a[i] + sum);
        ans = max(ans, sum);
    }
    cout<<ans<<'\n';
    return 0;
}