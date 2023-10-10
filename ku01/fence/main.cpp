#include <bits/stdc++.h>

using namespace std;

void cal(long long int x,long long int y){
    cout<<(x+y)*2<<"\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int h,w,q;cin>>h>>w>>q;
    int arr[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        int u=INT_MIN,d=INT_MAX,l=INT_MAX,r=INT_MIN;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(a==1){
                    if(arr[i][j]==b){
                        u=max(u,i);
                        d=min(d,i);
                        l=min(l,j);
                        r=max(r,j);
                    }
                }else{
                    if(arr[i][j]>=b){
                        u=max(u,i);
                        d=min(d,i);
                        l=min(l,j);
                        r=max(r,j);
                    }
                }
            }
        }
        if(u==INT_MIN or d==INT_MAX or l==INT_MAX or r==INT_MIN){
            cout<<0<<"\n";
        }else{
            cal(u-d+1,r-l+1);
        }
    }
    return 0;
}