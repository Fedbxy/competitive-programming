#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,d;cin>>n>>d;
        string s;cin>>s;
        if(s.size()==1){
            if(char(s[0])-48==0 and d==0){
                cout<<0<<'\n';
                continue;
            }
            if(char(s[0])-48>d){
                cout<<s[0]<<d<<'\n';
            }else cout<<d<<s[0]<<'\n';
            continue;
        }
        if(char(s[0])-48<d){
            cout<<d;
            for(int i=0;i<s.size();i++) cout<<s[i];
            cout<<'\n';
            continue;
        }else{
            for(int i=1;i<s.size();i++){
                // cout<<char(s[i-1])-48<<" > "<<d<<" and "<<char(s[i])-48<<" < "<<d<<'\n';
                if(char(s[i-1])-48 >= d and char(s[i])-48 < d){
                    for(int j=0;j<i;j++){
                        cout<<s[j];
                    }
                    cout<<d;
                    for(int j=i;j<s.size();j++){
                        cout<<s[j];
                    }
                    cout<<'\n';
                    break;
                }
                if(i==s.size()-1){
                    for(int i=0;i<s.size();i++) cout<<s[i];
                    cout<<d;
                    cout<<'\n';
                }
            }
        }
    }
    return 0;
}