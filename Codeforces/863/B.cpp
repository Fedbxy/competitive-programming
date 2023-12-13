#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;n*=2;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    int ans=INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            vector<int> b;
            for(int k=0;k<n;k++) if(k!=i and k!=j) b.push_back(a[k]);
            int sum=0;
            for(int k=0;k<n-2;k+=2) sum+=abs(b[k]-b[k+1]);
            ans=min(sum,ans);
        }
    }
    cout<<ans<<'\n';
    return 0;
}