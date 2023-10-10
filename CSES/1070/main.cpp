#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    if(n>=5){
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<"\n";
    }else if(n==1){
        cout<<1<<"\n";
    }else if(n==4){
        cout<<"2 4 1 3"<<"\n";
    }else{
        cout<<"NO SOLUTION"<<"\n";
    }
    return 0;
}