#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int w,h,n;cin>>w>>h>>n;
    ll l=0,r=1,ans;
    while((r/w) * (r/h) < n) r*=2;
    while(l<=r) {
        ll mid = (l+r)/2;
        if((mid/w) * (mid/h) >= n) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout<<ans<<'\n';
    return 0;
}