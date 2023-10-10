#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        char temp=s[0];
        string ans;
        for(int i=1;i<n;){
            if(s[i]==temp){
                ans.push_back(s[i]);
                if(i+2<n){
                    temp=s[i+1];
                    i+=2;
                    continue;
                }
            }
            i++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}