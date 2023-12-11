#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a,b,c;cin>>a>>b>>c;
    int sum=a+b+c;
    vector<string> ans = {"A","B+","B","C+","C","D+","D","F"};
    vector<int> check = {80,75,70,65,60,55,50,0};
    for(int i=0;i<check.size();i++) if(sum>=check[i]) {cout<<ans[i]<<'\n';break;}
    return 0;
}