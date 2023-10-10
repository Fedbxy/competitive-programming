#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,mn,mx;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(i==1){
            mx=temp;
            mn=temp;
            continue;
        }
        if(temp>mx){
            mx=temp;
        }
        if(temp<mn){
            mn=temp;
        }
    }
    cout<<mn<<endl;
    cout<<mx<<endl;
}