#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin>>s;
    int cpt=0,sml=0;

    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            cpt++;
        }else if(s[i]>='a' && s[i]<='z'){
            sml++;
        }
    }

    if(cpt>0&&sml>0){
        cout<<"Mix"<<endl;
    }else if(cpt>0){
        cout<<"All Capital Letter"<<endl;
    }else{
        cout<<"All Small Letter"<<endl;
    }

    return 0;
}