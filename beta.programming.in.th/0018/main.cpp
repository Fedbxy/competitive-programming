#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    vector<int> a(n-1);
    for(int i=2;i<=n;i++){
        a[i-2]=i;
        // cout<<i<<" ";
    }
    // cout<<"\n";
    int remaining=a.size(),p=2,count=0,temp=0;
    while(remaining>0){
        for(int i=0;i<n-1;i++){
            if(a[i]!=0){
                p=a[i];
                // cout<<"PRIME: "<<p<<"\n";
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(a[i]!=0){
                if(a[i]%p==0){
                    count++;
                    // cout<<count<<" CUT: "<<a[i]<<"\n";
                    if(count==k){
                        temp=a[i];
                        goto f;
                    }
                    a[i]=0;
                    remaining--;
                }
            }
        }
    }
    f:
    // cout<<"RESULT: "<<temp<<"\n";
    cout<<temp<<"\n";
    return 0;
}