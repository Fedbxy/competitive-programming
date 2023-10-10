#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("o.txt","w",stdout);
    int h,w,n;cin>>h>>w>>n;
    vector<vector<char>> arr(h+2,vector<char>(w+2,'#'));
    vector<vector<char>> temp(h+2,vector<char>(w+2,'#'));
    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            cin>>arr[i][j];
        }
    }
    while(n--){
        temp=arr;
        int a,b,c,d,l;cin>>a>>b>>c>>d>>l;
        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                if(i>a+l||i<a-l){
                    temp[i][j]='#';
                }
            }
        }
        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                cout<<temp[i][j];
            }
            cout<<"\n";
        }
        int y=a,x=b;
        while(true){
            if(y==c and x==d){
                cout<<1<<"\n";
                goto f;
            }
            if(temp[y-1][x]!='#'){
                temp[y][x]='#';
                y-=1;
                continue;
            }
            if(temp[y][x+1]!='#'){
                temp[y][x]='#';
                x+=1;
                continue;
            }
            if(temp[y+1][x]!='#'){
                temp[y][x]='#';
                y+=1;
                continue;
            }
            if(temp[y][x-1]!='#'){
                temp[y][x]='#';
                x-=1;
                continue;
            }
            cout<<0<<"\n";
            cout<<y<<" "<<x<<"\n";
            goto f;
        }
        f:
        cout<<"\n";
        continue;
    }
    return 0;
}