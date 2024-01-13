// written by fed
// score: 15/15

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s,v;
    getline(cin, v);
    transform(v.begin(), v.end(), v.begin(), ::tolower);
    // cout<<v<<'\n';
    for(char e:v) {
        if(!((e>='a' and e<='z') or (e>='0' and e<='9'))) continue;
        s.push_back(e);
    }
    // cout<<s<<'\n';
    bool ans=1;
    for(int i=0;i<s.size()/2;i++) {
        // cout<<s[i]<<" "<<s[s.size()-i-1]<<'\n';
        if(s[i]!=s[s.size()-i-1]) {ans=0;break;}
    }
    cout<<ans<<'\n';
    return 0;
}