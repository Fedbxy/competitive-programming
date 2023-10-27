#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> &a, double mid, int k) {
    int sum=0;
    for(int i=0;i<a.size();i++) {
        sum+=a[i]/mid;
    }
    return sum>=k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    double l=0,r=*max_element(a.begin(),a.end());
    double ans;
    while(l<=r) {
        double mid = (l+r)/2;
        if(ok(a,mid,k)) {
            l = mid + 1e-6;
            ans = mid;
        } else {
            r = mid - 1e-6;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}