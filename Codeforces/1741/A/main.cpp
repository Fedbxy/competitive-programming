#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    map<char,int> m;
    m['S']=0;
    m['M']=1;
    m['L']=2;
    while(t--){
        string s1,s2;cin>>s1>>s2;
        char lchr1=s1[s1.size()-1],lchr2=s2[s2.size()-1];
        if(s1.size()==s2.size() and lchr1==lchr2){
            cout<<"=\n";
            continue;
        }
        if(m[lchr1]>m[lchr2]){
            cout<<">\n";
            continue;
        }
        if(m[lchr1]<m[lchr2]){
            cout<<"<\n";
            continue;
        }
        if(m[lchr1]==m[lchr2]){
            if(lchr1=='S'){
                if(s1.size()>s2.size()){
                    cout<<"<\n";
                }else cout<<">\n";
            }else{
                if(s1.size()>s2.size()){
                    cout<<">\n";
                }else cout<<"<\n";
            }
        }
    }
    return 0;
}