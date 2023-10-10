/*
LANG: C++
TASK: slide
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int a[n];
    for(int i=n-1;i>=0;i--){
        cin>>a[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
            }
        }
    }
    cout<<count<<"\n";
    return 0;
}