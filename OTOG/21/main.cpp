#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;cin>>s;
    int cnt=0,ans=1;
    for(auto e:s) {
        if(e == 'i') cnt++;
        else if(e == ')') {
            ans*=cnt+1;
            cnt=0;
        }
    }
    if(cnt!=0) ans*=cnt+1;
    cout<<ans<<'\n';
    return 0;
}