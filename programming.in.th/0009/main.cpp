#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a,a+3);
    string v;cin>>v;
    for(int i=0;i<3;i++){
        if(v[i]=='A'){
            cout<<a[0];
        }else if(v[i]=='B'){
            cout<<a[1];
        }else{
            cout<<a[2];
        }
        if(i!=2){
            cout<<" ";
        }else{
            cout<<"\n";
        }
    }
    return 0;
}