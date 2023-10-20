#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;cin>>s;
    unordered_map<char,int> m;
    for(int i=0;i<s.size();i++) if(isascii(s[i])) m[s[i]]++;
    int mx=INT_MIN;
    for(auto e:m) mx=max(mx,e.second);
    cout<<mx<<'\n';
    return 0;
}