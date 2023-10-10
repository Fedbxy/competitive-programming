#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;getline(cin,s);
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            if(count==2){
                s[i]='0';
                count=0;
            }else{
                count++;
            }
        }
        if(s[i]=='p'&&count==1){
            s[i]='0';
            count++;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!='0'){
            cout<<s[i];
        }
    }
    cout<<"\n";
    return 0;
}