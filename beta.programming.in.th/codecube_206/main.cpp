#include <bits/stdc++.h>

using namespace std;
using lli=long long int;

lli n;

bool ok(lli x){
    return 23*x+98*(x/12)>=n;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    lli l=1,r=n/23+10;
    lli ans;
    while(l<=r){
        lli mid=(l+r)/2;
        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans*7<<"\n";
    return 0;
}