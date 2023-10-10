#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> col[m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c;cin>>c;
                col[j].push_back(c);
            }
        }
        for(int j=0;j<m;j++) sort(col[j].begin(),col[j].end());
        ll ans=0;
        for(int j=0;j<m;j++){
            vector<ll> ps(n);
            for(int i=0;i<n;i++){
                ps[i]=col[j][i];
                if(i-1>=0) ps[i]+=ps[i-1];
            }
            for(int i=n-1;i>0;i--){
                ans+=(1LL * col[j][i] * i) - ps[i-1];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}