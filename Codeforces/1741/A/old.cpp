#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        string a,b;cin>>a>>b;
        char la=a[a.size()-1],lb=b[b.size()-1];
        if(a.size()==1&&b.size()==1){
            if(la<lb){
                cout<<">"<<endl;
            }else if(la==lb){
                cout<<"="<<endl;
            }else if(la>lb){
                cout<<"<"<<endl;
            }
        }else{
            if(a.size()>b.size()){
                if(la=='S'){
                    cout<<"<"<<endl;
                }else if(la=='L'){
                    cout<<">"<<endl;
                }
            }else if(a.size()<b.size()){
                if(la=='S'){
                    cout<<">"<<endl;
                }else if(la=='L'){
                    cout<<"<"<<endl;
                }
            }else{
                cout<<"="<<endl;
            }
        }
    }
    return 0;
}