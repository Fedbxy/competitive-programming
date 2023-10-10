#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    vector<int> a(3,0);a[0]=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            swap(a[0],a[1]);
        }else if(s[i]=='B'){
            swap(a[1],a[2]);
        }else{
            swap(a[0],a[2]);
        }
    }
    for(int i=0;i<3;i++){
        if(a[i]==1){
            cout<<i+1<<"\n";
            break;
        }
    }
    return 0;
}