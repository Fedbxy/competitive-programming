#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(q--) {
        int l,r;cin>>l>>r;
        int sz=r-l+1;
        vector<int> arr(sz);
        for(int i=l;i<=r;i++) arr[i-l]=a[i];
        sort(arr.begin(), arr.end());
        for(int i=0;i<sz;i++) cout<<arr[i]<<(i==sz-1 ? '\n' : ' ');
    }
    return 0;
}