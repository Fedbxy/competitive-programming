#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        queue<int> q;
        q.push(n);
        bool ans=0;
        while(!q.empty()){
            int x=q.front();
            if(x==m){
                ans=1;
                break;
            }
            if(x%3!=0){
                q.pop();
                continue;
            }
            q.pop();
            q.push((x/3)*2);
            q.push(x/3);
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}