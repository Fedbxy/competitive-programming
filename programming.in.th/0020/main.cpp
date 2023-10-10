#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int a[5][4];
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
        }
    }
    int max=0,imax;
    for(int i=0;i<5;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=a[i][j];
        }
        if(sum>max){
            max=sum;
            imax=i;
        }
    }
    cout<<imax+1<<" "<<max<<"\n";
    return 0;
}