#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int a[N];
int n;

void destroy(int idx){
    if(a[idx]==1){
        if(idx-1>=0){
            if(a[idx-1]==1) a[idx-1]=0;
            else if(a[idx-1]==0) a[idx-1]=1;
        }
        if(idx+1<n){
            if(a[idx+1]==1) a[idx+1]=0;
            else if(a[idx+1]==0) a[idx+1]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    return 0;
}