#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> a(n,INT_MAX);
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int count=1;
    for(int i=0;i<n;i++){
        if(a[i]==count){
            count++;
        }else{
            cout<<count<<"\n";
            break;
        }
    }
    return 0;
}