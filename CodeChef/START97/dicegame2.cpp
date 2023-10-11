#include <bits/stdc++.h>

using namespace std;

void solve(){
    vector<int> a(3);
    vector<int> b(3);
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ansa=a[2]+a[1],ansb=b[2]+b[1];
    if(ansa>ansb) cout<<"Alice\n";
    else if(ansa<ansb) cout<<"Bob\n";
    else cout<<"Tie\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}