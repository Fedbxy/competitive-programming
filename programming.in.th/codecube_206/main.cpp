#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;cin>>n;
    ll l=0,r=1e18/23,ans;
    while(l<=r) {
        ll mid = (l+r)/2;
        if(23*mid+98*(mid/12)>=n) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout<<7*ans<<'\n';
    return 0;
}