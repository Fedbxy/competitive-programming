#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        if(x+y>6) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}