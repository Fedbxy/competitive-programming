#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;cin>>s;
    int n = s.size();
    vector<int> a(n),b(26);
    for(int i=0;i<n;i++) cin>>a[i];

    int mx=INT_MIN;
    for(int j=0;j<100;j++) {
        // cout<<j+1<<" ";
        for(int i=0;i<n;i++) {
            if(s[i]+a[i]>'Z') s[i]+=a[i]-26;
            else s[i]+=a[i];
        }
        for(int i=0;i<n;i++) b[s[i]-'A']++;
        int temp=INT_MIN;
        for(int i=0;i<26;i++) temp=max(b[i],temp);
        mx=max(temp,mx);
        for(int i=0;i<26;i++) b[i]=0;
        // cout<<s<<" "<<temp<<'\n';
    }
    cout<<mx<<'\n';
    return 0;
}