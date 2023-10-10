#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("input.txt","r",stdin);
    int n;cin>>n;
    stack<int> s;
    while(n--){
        string cmd;cin>>cmd;
        if(cmd ==  "push"){
            int x;cin>>x;
            s.push(x);
        }else{
            if(s.empty()){
                cout<<"null\n";
                continue;
            }
            int x=s.top();
            s.pop();
            cout<<x<<'\n';
        }
    }
    return 0;
}