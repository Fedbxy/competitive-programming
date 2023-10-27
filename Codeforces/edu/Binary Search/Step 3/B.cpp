#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ok(vector<int> &a, int k, ll mid) {
    ll cnt=1,sum=0;
    for(int i=0;i<a.size();i++) {
        sum+=a[i];
        if(sum>mid) {
            cnt++;
            sum=a[i];
        }
    }
    return cnt<=k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll l=*max_element(a.begin(),a.end()),r=0,ans;
    for(int i=0;i<n;i++) r+=a[i];
    while(l<=r) {
        ll mid = (l+r)/2;
        if(ok(a, k, mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout<<ans<<'\n';
    return 0;
}