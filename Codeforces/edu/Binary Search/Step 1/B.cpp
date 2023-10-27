#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(k--) {
        int q;cin>>q;
        int l=0,r=n-1,ans=-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(a[mid]<=q) {
                l = mid + 1;
                ans = mid;
            } else r = mid - 1;
        }
        cout<<ans+1<<'\n';
    }
    return 0;
}