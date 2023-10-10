#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
        // int x;cin>>x;
        // int x_temp=x;
        // int size=0;
        // while(x_temp>=1){
        //     x_temp/=10;
        //     size++;
        // }
        // bool isBreak=false;
        // for(int i=size;i>=size/2;i--){
        //     int temp=pow(10,size-i+1);
        //     cout<<floor(x/pow(10,i-1))<<"="<<x%temp<<"\n";
        //     if(floor(x/pow(10,i-1))!=x%temp){
        //         isBreak=true;
        //         break;
        //     }
        // }
        // if(!isBreak){
        //     cout<<"true"<<"\n";
        // }else{
        //     cout<<"false"<<"\n";
        // }
        int x;cin>>x;
        string s=to_string(x);
        bool isBreak=false;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[s.size()-i-1]){
                isBreak=true;
                break;
            }
        }
        if(!isBreak){
            cout<<"true"<<"\n";
        }else{
            cout<<"false"<<"\n";
        }
    return 0;
}