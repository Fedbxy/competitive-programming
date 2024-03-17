#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    queue<int> q;
    while(n--){
        string cmd;cin>>cmd;
        if(cmd=="push"){
            int x;cin>>x;
            q.push(x);
        }else{
            if(q.empty()){
                cout<<"null\n";
                continue;
            }
            cout<<q.front()<<'\n';
            q.pop();
        }
    }
    return 0;
}