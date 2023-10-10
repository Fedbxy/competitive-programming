#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,s;cin>>n>>s;
    vector<int> a(n);
    vector<int> sent(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=s-1;
    int count=0;
    while(c!=-1){
        if(sent[c]==0){
            sent[c]=1;
            count++;
        }else{
            break;
        }
        c=a[c]-1;
    }
    cout<<count<<"\n";
    return 0;
}