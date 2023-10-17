#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll func(ll n) {
    if(n==1) return 69;
    if(n%2==0) return func(n-1) + n;
    return func(n-1) + func(n-2) + n;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;cin>>q;
    while(q--) {
        ll n;cin>>n;
        cout<<func(n)<<'\n';
    }
    return 0;
}