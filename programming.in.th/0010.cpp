#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;cin>>s;
    vector<bool> a(3);a[0]=1;
    for(int i=0;i<s.size();i++) if(s[i]=='A') swap(a[0], a[1]); else if(s[i]=='B') swap(a[1], a[2]); else swap(a[0], a[2]);
    for(int i=0;i<3;i++) if(a[i]) cout<<i+1<<'\n';
    return 0;
}