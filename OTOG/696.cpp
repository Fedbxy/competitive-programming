#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> a[n];
    for(int i=0;i<n;i++){
        int p;cin>>p;
        a[i].resize(p);
        for(int j=0;j<p;j++){
            cin>>a[i][j];
        }
    }
    while(m--){
        int x,y;
        char cmd;
        cin>>x>>cmd>>y;
        x-=1;y-=1;
        if(cmd=='U'){
            set<int> ans;
            for(int i=0;i<a[x].size();i++) ans.insert(a[x][i]);
            for(int i=0;i<a[y].size();i++) ans.insert(a[y][i]);
            if(ans.empty()){
                cout<<"Empty\n";
                continue;
            }
            for(auto e:ans) cout<<e<<' ';
            cout<<'\n';
        }else if(cmd=='|'){
            set<int> ans,setx,sety;
            for(int i=0;i<a[x].size();i++) setx.insert(a[x][i]);
            for(int i=0;i<a[y].size();i++) sety.insert(a[y][i]);
            for(auto e:setx){
                if(sety.find(e)!=sety.end()) ans.insert(e);
            }
            if(ans.empty()){
                cout<<"Empty\n";
                continue;
            }
            for(auto e:ans) cout<<e<<' ';
            cout<<'\n';
        }else{
            set<int> ans,setx,sety;
            for(int i=0;i<a[x].size();i++) setx.insert(a[x][i]);
            for(int i=0;i<a[y].size();i++) sety.insert(a[y][i]);
            for(auto e:setx){
                if(sety.find(e)==sety.end()) ans.insert(e);
            }
            if(ans.empty()){
                cout<<"Empty\n";
                continue;
            }
            for(auto e:ans) cout<<e<<' ';
            cout<<'\n';
        }
    }
    return 0;
}