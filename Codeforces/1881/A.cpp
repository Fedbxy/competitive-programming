#include <bits/stdc++.h>

using namespace std;

void solve() {
    // cout<<"START\n";
    int n,m;cin>>n>>m;
    string x,s;cin>>x>>s;
    int cnt=0;
    while(x.size()<s.size()) {
        x+=x;
        cnt++;
    }
    size_t q = x.find(s);
    if(q != string::npos) {
        cout<<cnt<<'\n';
        return;
    }
    // cout<<".\n";
    for(int i=0;i<3;i++) {
        x+=x;
        cnt++;
        size_t qi = x.find(s);
        if(qi != string::npos) {
            cout<<cnt<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int t;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}