#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    string s,temp;cin>>s;
    // cout<<s<<'\n';
    for(int i=0;i<s.size();i++) {
        if(s[i]!=',') {
            temp.push_back(s[i]);
        } else {
            cout<<char(stoi(temp));
            temp="";
        }
    }
    cout<<char(stoi(temp))<<'\n';
    return 0;
}