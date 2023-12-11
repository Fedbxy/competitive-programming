#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;cin>>s;
    string orgnl = s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    if(orgnl == s) {cout<<"All Capital Letter\n";return 0;}
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(orgnl == s) {cout<<"All Small Letter\n";return 0;}
    cout<<"Mix\n";
    return 0;
}