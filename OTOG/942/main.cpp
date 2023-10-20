#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("i.txt","r",stdin);
    int n,q;cin>>n>>q;
    map<double,int> m;
    for(int i=-1;i<n-1;i++) m[i]=0;
    while(q--) {
        string cmd;cin>>cmd;
        if(cmd=="pi") {
            double k;cin>>k;
            if(k>n-2) {
                cout<<"error\n";
                continue;
            }
            if(m.find(k)!=m.end()) cout<<m[k]<<'\n';
            else cout<<"0\n";
        } else if(cmd=="pa") {
            for(auto e:m) cout<<e.second<<' ';
            cout<<'\n';
        } else if(cmd=="i") {
            double k;
            int v;
            cin>>k>>v;
            if(k>n-2) {
                cout<<"error\n";
                continue;
            }
            m[k]=v;
        }
    }
    return 0;
}