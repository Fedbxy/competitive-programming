#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> &a, int k, int mid) {
    int cnt=1,sum=0;
    for(int i=0;i<a.size();i++) {
        sum+=a[i];
        if(sum>mid) {
            sum=a[i];
            cnt++;
        }
    }
    return cnt<=k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=*max_element(a.begin(), a.end()),r=0,ans;
    for(int i=0;i<n;i++) r+=a[i];
    while(l<=r) {
        int mid = (l+r)/2;
        if(ok(a, k, mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout<<ans<<'\n';
    return 0;
}