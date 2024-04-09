#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    int ans = 0;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        if(a+b+c>=2) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}