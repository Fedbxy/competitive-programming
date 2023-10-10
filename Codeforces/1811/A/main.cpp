#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int t;cin>>t;
    while(t--){
        int n,d;cin>>n>>d;
        string s;cin>>s;
        string mx=s+to_string(d);
        for(int i=0;i<n;i++){
            if(s[i]-'0'<d){
                mx=s.substr(0,i)+to_string(d)+s.substr(i);
                break;
            }
        }
        cout<<mx<<'\n';
    }
    return 0;
}