#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        vector<int> a(26);
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
            a[s[i]-'a']++;
        }
        sort(a.begin(),a.end(),greater<int>());
        int ans=0;
        for(int i=0;i<a.size();i++){
            ans+=(a[i]*(26-i));
        }
        cout<<ans<<'\n';
    }
    return 0;
}