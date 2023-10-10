#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int a[9],total=0;
    for(int i=0;i<9;i++){
        cin>>a[i];
        total+=a[i];
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(total-a[i]-a[j]==100){
                for(int k=0;k<9;k++){
                    if(k!=i&&k!=j){
                        cout<<a[k]<<"\n";
                    }
                }
            }
        }
    }
    return 0;
}