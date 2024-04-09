#include <bits/stdc++.h>

using namespace std;

const string text = "codeforces";

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int cnt=0;
        for(int i=0;i<10;i++){
            if(s[i]!=text[i]) cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}