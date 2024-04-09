#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        int sum=0;
        if(n<=1){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<n/2;i++){
            // cout<<"# "<<a[n-i-1]<<" - "<<a[i]<<" = "<<a[n-i-1]-a[i]<<'\n';
            sum+=a[n-i-1]-a[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}