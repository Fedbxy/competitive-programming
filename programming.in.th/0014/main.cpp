#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int x,y;cin>>x>>y;
    while(x*y!=0){
        if(x>y){
            x-=y;
        }else{
            y-=x;
        }
    }
    if(x==0){
        cout<<y<<"\n";
    }else{
        cout<<x<<"\n";
    }
    return 0;
}