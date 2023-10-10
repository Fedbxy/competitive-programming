#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin>>s;
    if(s.size()>1){
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size()-i;j++){
                if((s[i-1]>='a' && s[i-1]<='z') && (s[i+j-1]>='a' && s[i+j-1]<='z')){
                    if(i==s.size()-1){
                        cout<<"All Small Letter"<<endl;
                    }
                }else if((s[i-1]>='A' && s[i-1]<='Z') && (s[i+j-1]>='A' && s[i+j-1]<='Z')){
                    if(i==s.size()-1){
                        cout<<"All Capital Letter"<<endl;
                    }
                }else{
                    cout<<"Mix"<<endl;
                    goto End;
                }
            }
        }
    }else{
        if(s[0]>='a' && s[0]<='z'){
            cout<<"All Small Letter"<<endl;
        }else if(s[0]>='A' && s[0]<='Z'){
            cout<<"All Capital Letter"<<endl;
        }else{
            cout<<"???"<<endl;
        }
    }
    End:;
}