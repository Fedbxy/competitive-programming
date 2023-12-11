#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    unordered_set<int> s;
    for(int i=0;i<10;i++) {int v;cin>>v;s.insert(v%42);}
    cout<<s.size()<<'\n';
    return 0;
}