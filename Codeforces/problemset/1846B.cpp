#include <bits/stdc++.h>

using namespace std;

void solve() {
    char a[3][3];
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
        }
    }
    set<char> ans;
    for(int i=0;i<3;i++) if(a[i][0]==a[i][1] and a[i][1]==a[i][2]) ans.insert(a[i][0]);
    for(int i=0;i<3;i++) if(a[0][i]==a[1][i] and a[1][i]==a[2][i]) ans.insert(a[0][i]);
    if(a[0][0]==a[1][1] and a[1][1]==a[2][2]) ans.insert(a[0][0]);
    if(a[0][2]==a[1][1] and a[1][1]==a[2][0]) ans.insert(a[1][1]);
    if(ans.size()>0) {
        for(int i=0;i<ans.size();i++) {
            auto itr=next(ans.begin(),i);
            if(*itr=='.') ans.erase(itr);
        }
    }
    if(ans.size()==1) {
        cout<<*ans.begin()<<'\n';
    } else {
        cout<<"DRAW\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}