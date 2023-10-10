#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int min=INT_MAX;
    for(int i=1;i<pow(2,n);i++){
        int s=1,b=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                s*=a[j].first;
                b+=a[j].second;
            }
        }
        if(abs(s-b)<min){
            min=abs(s-b);
        }
    }
    cout<<min<<"\n";
    return 0;
}