#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n;cin>>n;
        string s;cin>>s;
        if(n!=5){
            cout<<"NO"<<endl;
            continue;
        }
        int l_T=0,l_i=0,l_m=0,l_u=0,l_r=0;
        for(int j=0;j<n;j++){
            if(s[j]=='T'){
                l_T++;
            }else if(s[j]=='i'){
                l_i++;
            }else if(s[j]=='m'){
                l_m++;
            }else if(s[j]=='u'){
                l_u++;
            }else if(s[j]=='r'){
                l_r++;
            }
        }
        if(l_T==1&&l_i==1&&l_m==1&&l_u==1&&l_r==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}