#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int w,h,n;cin>>w>>h>>n;
    int l=0,r=max(w,h)*n;
    while(l+1<r){
        int mid=(l+r)/2;
        if((mid/w)*(mid/h)>=n){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<"\n";
    return 0;
}