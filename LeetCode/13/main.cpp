#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    map<char,int> a;
    a['I']=1;a['V']=5;a['X']=10;a['L']=50;a['C']=100;a['D']=500;a['M']=1000;
    int ans=0;
    int i=0;
    while(i<s.size()){
        if(a[s[i]]<a[s[i+1]]){
            ans+=a[s[i+1]]-a[s[i]];
            i+=2;
        }else{
            ans+=a[s[i]];
            i++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}