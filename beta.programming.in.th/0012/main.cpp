#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;cin>>s;
    cout<<"..";
    for(int j=0;j<s.size();j++){
        if((j+1)%3!=0){
            cout<<"#";
        }else{
            cout<<"*";
        }
        if(j!=s.size()-1){
            cout<<"...";
        }else{
            cout<<"..";
        }
    }
    cout<<"\n";
    cout<<".";
    for(int j=0;j<s.size();j++){
        if((j+1)%3!=0){
            cout<<"#.#.";
        }else{
            cout<<"*.*.";
        }
    }
    cout<<"\n";
    cout<<"#";
    int temp=s.size();
    for(int j=0;j<s.size();j++){
        if((j+1)%3!=0&&(j+1)%3!=2&&s.size()){
            cout<<"."<<s[j]<<".#";
        }else{
            if(temp>=3){
                cout<<"."<<s[j]<<".*";
            }else{
                cout<<"."<<s[j]<<".#";
            }
        }
        if((j+1)%3==0){
            temp-=3;
        }
    }
    cout<<"\n";
    cout<<".";
    for(int j=0;j<s.size();j++){
        if((j+1)%3!=0){
            cout<<"#.#";
        }else{
            cout<<"*.*";
        }
        cout<<".";
    }
    cout<<"\n";
    cout<<"..";
    for(int j=0;j<s.size();j++){
        if((j+1)%3!=0){
            cout<<"#";
        }else{
            cout<<"*";
        }
        if(j!=s.size()-1){
            cout<<"...";
        }else{
            cout<<"..";
        }
    }
    cout<<"\n";
    return 0;
}