#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,x,y;cin>>n>>x>>y;
    int l=0,r=2e8*10,ans;
    while(l<=r) {
        int mid = (l+r)/2;
        if(mid/x + mid/y >= n-1) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout<<ans+min(x,y)<<'\n';
    return 0;
}