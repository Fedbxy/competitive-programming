#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> a(3);
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a.begin(), a.end());
    string s;cin>>s;
    for(int i=0;i<3;i++) cout<<a[s[i]-'A']<<(i==2 ? "\n" : " ");
    return 0;
}