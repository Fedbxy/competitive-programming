#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<*min_element(a.begin(),a.end())<<'\n';
    cout<<*max_element(a.begin(),a.end())<<'\n';
    return 0;
}