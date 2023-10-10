#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int x;
        int mx=0,c=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==0) c++;
            else{
                mx=max(mx,c);
                c=0;
            }
        }
        mx=max(mx,c);
        cout<<mx<<'\n';
    }
    return 0;
}