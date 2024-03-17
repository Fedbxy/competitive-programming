#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> odd;
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            odd.push_back(a[i]);
        }
    }
    sort(odd.begin(),odd.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]%2!=0){
            a[i]=odd[cnt];
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i==n-1) cout<<'\n';
        else cout<<' ';
    }
    return 0;
}