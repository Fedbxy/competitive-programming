#include <bits/stdc++.h>

using namespace std;
using psv = pair<string,vector<int>>;

vector<int> func(string s){
    vector<int> ans(26);
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' and s[i]<='z'){
            ans[s[i]-'a']++;
        }
    }
    return ans;
}

bool cmp(const psv &l, const psv &r){
    for(int i=0;i<26;i++){
        if(l.second[i]==r.second[i]) continue;
        return l.second[i]>r.second[i];
    }
    return l.first<r.first;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<psv> a(n);
    for(int i=0;i<n;i++){
        string s;cin>>s;
        a[i].first=s;
        a[i].second=func(s);
    }
    sort(a.begin(),a.end(),cmp);
    for(auto e:a) cout<<e.first<<'\n';
    return 0;
}