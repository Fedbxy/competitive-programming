#include <bits/stdc++.h>

using namespace std;

bool isUpper(char c){
    if(c>='A' and c<='Z'){
        return 1;
    }
    return 0;
}

char convert(char c){
    if(isUpper(c)) return char((c-'A')+'a');
    return char((c-'a')+'A');
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        s[i]=convert(s[i]);
    }
    cout<<s<<'\n';
    return 0;
}