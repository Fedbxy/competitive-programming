#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x,k,p;cin>>n>>x>>k>>p;
        if(k >= x){
            p += x * 10 + (k-x) * 5;
        }else{
            p += k * 10;
        }
        if(k == n) p+=20;
        cout<<p<<'\n';
    }
    return 0;
}