#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<ll> a(n);
    while(m--) {
        char c;cin>>c;
        if(c=='B') {
            int idx;cin>>idx;
            ll score;cin>>score;
            a[idx-1] = score;
        } else {
            int idx;cin>>idx;
            cout<<*max_element(a.begin(), a.begin()+idx)<<'\n';
        }
    }
    return 0;
}