#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int count=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if((i*2)%int(pow(2,j))==0){
                cout<<count<<": ";
                count++;
                for(int k=0;k<j;k++){
                    cout<<"*";
                }
                cout<<"\n";
                break;
            }
        }
    }
    return 0;
}