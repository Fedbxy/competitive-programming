#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        bool ans=false;
        for(int i=0;i<n;i++){
            int mx_a=*max_element(a.begin(),a.end()),mx_b=*max_element(b.begin(),b.end());
            if(a[i]>a[n-1] or b[i]>b[n-1]) swap(a[i],b[i]);
            if(a[n-1]==mx_a and b[n-1]==mx_b) ans=true;
        }
        if(ans)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}