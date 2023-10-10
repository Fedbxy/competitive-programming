#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int count=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            count+=a[i]-a[i+1];
            a[i+1]=a[i];
        }
    }
    cout<<count<<"\n";
    return 0;
}