#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int n,k;
vector<int> a;

bool ok(lli x){
    int cnt=1;
    lli sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>x){
            cnt++;
            sum=a[i];
        }
    }
    return cnt<=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int v;cin>>v;
        a.push_back(v);
    }
    int mx;
    lli sum=0,ans;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i]);
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    lli l=mx,r=sum;
    while(l<=r){
        lli mid=(l+r)/2;
        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}