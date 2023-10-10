#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ONEtoN(ll n){
    return (n*(n+1))/2;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k,q;cin>>n>>k>>q;
        vector<int> a;
        int cnt=0;
        for(int i=0;i<n;i++){
            int v;cin>>v;
            if(v>q){
                if(cnt!=0) a.push_back(cnt);
                cnt=0;
            }else cnt++;
        }
        if(cnt!=0) a.push_back(cnt);
        ll sum=0;
        for(int i=0;i<a.size();i++){
            int mx=a[i];
            if(k>mx){
                continue;
            }
            sum+=ONEtoN(mx-k+1);
        }
        cout<<sum<<'\n';
    }
    return 0;
}