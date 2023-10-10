#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    set<int> s;
    for(int i=0;i<10;i++){
        int v;cin>>v;
        s.insert(v%42);
    }
    cout<<s.size()<<"\n";
    return 0;
}