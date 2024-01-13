// written by fed
// score: 3/15
// this is NOT the solution to this problem

#include <bits/stdc++.h>

using namespace std;

const vector<char> arr = {'a','e','i','o','u','A','E','I','O','U'};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    if(n>5) {cout<<"error\n";return 0;}
    vector<string> a(n),ans(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        for(auto e:a[i]) if(!((e>='A' and e<='Z') or (e>='a' and e<='z'))) {cout<<"error\n";return 0;}
    }
    for(int i=0;i<n/2;i++) {
        string s1=a[i],s2=a[n-i-1];
        string con1,con2;
        int cnt1=0,cnt2=0;
        for(auto e:s1) {
            if(e=='y' or e=='Y') {con1.push_back(e);cnt1++;break;}
            if(find(arr.begin(), arr.end(), e) != arr.end()) break;
            con1.push_back(e);
            cnt1++;
        }
        for(auto e:s2) {
            if(e=='y' or e=='Y') {con2.push_back(e);cnt2++;break;}
            if(find(arr.begin(), arr.end(), e) != arr.end()) break;
            con2.push_back(e);
            cnt2++;
        }
        ans[i]=con2;
        for(int j=cnt1;j<s1.size();j++) ans[i].push_back(s1[j]);
        ans[n-i-1]=con1;
        for(int j=cnt2;j<s2.size();j++) ans[n-i-1].push_back(s2[j]);
    }
    if(n%2!=0) ans[n/2]=a[n/2];
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<(i==ans.size()-1 ? "\n" : " ");
    return 0;
}