#include <bits/stdc++.h>

using namespace std;

const string https="https";

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    string s,v;
    bool isFirst=true;
    while(cin>>v) s+=v;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='h') {
            if(i+4<s.size()) {
                bool b=false;
                for(int j=0;j<5;j++) {
                    if(s[i+j]!=https[j]) {
                        b=true;
                        break;
                    }
                }
                if(!b and !isFirst) {
                    cout<<'\n';
                }
                if(isFirst) isFirst=false;
            }
        }
        cout<<s[i];
    }
    cout<<'\n';
    return 0;
}