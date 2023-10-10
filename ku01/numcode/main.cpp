#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,t;cin>>n>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(t==1){
        int prev;
        for(int i=0;i<n;i++){
            if(i==0){
                if(a[i]>n){
                    cout<<1<<"\n";
                }else{
                    cout<<0<<"\n";
                }
            }else{
                if(prev<a[i]){
                    cout<<1<<"\n";
                }else{
                    cout<<0<<"\n";
                }
            }
            prev=a[i];
        }
    }else{
        for(int i=1;i<n;i++){
            if(a[i]>2*a[i-1]){
                a[i]=a[i]-2*a[i-1];
            }else{
                a[i]=a[i]-a[i-1];
            }
        }
        int prev;
        for(int i=0;i<n;i++){
            if(i==0){
                if(a[i]>n){
                    cout<<1<<"\n";
                }else{
                    cout<<0<<"\n";
                }
            }else{
                if(prev<a[i]){
                    cout<<1<<"\n";
                }else{
                    cout<<0<<"\n";
                }
            }
            prev=a[i];
        }
    }
    return 0;
}