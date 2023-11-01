#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    for(int i=0;i<n;i++) c[i]=a[i]+b[i];
    cout<<*max_element(c.begin(), c.end())-*min_element(c.begin(), c.end())<<'\n';
    return 0;
}