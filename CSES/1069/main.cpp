#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    int count=0,mx=INT_MIN;
    char last=s[0];
    for(int i=0;i<s.size();i++){
        if(s[i]==last){
            count++;
        }else{
            mx=max(mx,count);
            count=1;
        }
        last=s[i];
    }
    mx=max(mx,count);
    cout<<mx<<"\n";
    return 0;
}