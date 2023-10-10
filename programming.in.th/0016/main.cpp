#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int Adrian=0,Bruno=0,Goran=0;
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=1;i<=n;i++){
        if(i%3==1){
            if(s[i-1]=='A'){
                Adrian++;
            }
        }else if(i%3==2){
            if(s[i-1]=='B'){
                Adrian++;
            }
        }else if(i%3==0){
            if(s[i-1]=='C'){
                Adrian++;
            }
        }

        if(i%2==1){
            if(s[i-1]=='B'){
                Bruno++;
            }
        }else if(i%4==2){
            if(s[i-1]=='A'){
                Bruno++;
            }
        }else if(i%4==0){
            if(s[i-1]=='C'){
                Bruno++;
            }
        }

        if(i%6==1||i%6==2){
            if(s[i-1]=='C'){
                Goran++;
            }
        }else if(i%6==3||i%6==4){
            if(s[i-1]=='A'){
                Goran++;
            }
        }if(i%6==5||i%6==0){
            if(s[i-1]=='B'){
                Goran++;
            }
        }
    }
    int mx=max(max(Adrian,Bruno),Goran);
    cout<<mx<<endl;
    if(Adrian==mx){
        cout<<"Adrian"<<endl;
    }
    if(Bruno==mx){
        cout<<"Bruno"<<endl;
    }
    if(Goran==mx){
        cout<<"Goran"<<endl;
    }

    return 0;
}