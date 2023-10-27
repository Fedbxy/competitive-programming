#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(k--) {
        int q;cin>>q;
        int l=0,r=n-1;
        bool ans = false;
        while(l<=r) {
            int mid = (l+r)/2;
            if(a[mid]==q) {
                ans = true;
                break;
            } else if(a[mid]>q) r = mid - 1;
            else l = mid + 1;
        }
        cout<<(ans ? "YES\n" : "NO\n");
    }
    return 0;
}