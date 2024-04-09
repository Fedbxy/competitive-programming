#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int b[n-1];
        for(int i=0;i<n-1;i++){
            cin>>b[i];
        }
        int a[n];
        a[0]=b[0];
        a[n-1]=b[n-2];
        for(int i=1;i<n-1;i++){
            a[i]=min(b[i-1],b[i]);
        }
        for(int e:a){
            cout<<e<<' ';
        }
    }
    return 0;
}