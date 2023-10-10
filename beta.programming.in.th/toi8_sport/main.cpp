#include <bits/stdc++.h>

using namespace std;

int k;

void f(int cntA,int cntB,string s){
    if(cntA==k or cntB==k){
        for(int i=0;i<s.size()-1;i++){
            cout<<s[i]<<" ";
        }
        cout<<s[s.size()-1]<<"\n";
        return;
    }
    if(cntA+1<=k) f(cntA+1,cntB,s+"W");
    if(cntB+1<=k) f(cntA,cntB+1,s+"L");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>k;
    int a,b;cin>>a>>b;
    f(a,b,"");
    return 0;
}