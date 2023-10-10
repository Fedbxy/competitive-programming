#include <bits/stdc++.h>

using namespace std;

int n;

char togglec(char c){
    if(c=='*') return '-';
    return '*';
}

vector<vector<char>> recur(vector<vector<char>> &a, int i, int j, char c, int cnt, char dir){
    if(cnt>=n*n){
        // cout<<"DONE\n";
        return a;
    }
    a[i][j]=c;
    // cout<<cnt<<": "<<a[i][j]<<'\n';
    // cout<<a[i][j];
    if(dir=='R'){
        if(j+1<n and a[i][j+1]==a[i][j]) recur(a, i+1, j, togglec(c), cnt+1, 'D');
        else{
            if(j+1>=n or a[i][j+1]==togglec(c)) recur(a, i+1, j, c, cnt+1, 'D');
            else recur(a, i, j+1, c, cnt+1, 'R');
        }
    }else if(dir=='D'){
        if(i+1<n and a[i+1][j]==a[i][j]) recur(a, i, j-1, togglec(c), cnt+1, 'L');
        else{
            if(i+1>=n or a[i+1][j]==togglec(c)) recur(a, i, j-1, c, cnt+1, 'L');
            else recur(a, i+1, j, c, cnt+1, 'D');
        }
    }else if(dir=='L'){
        if(j-1>=0 and a[i][j-1]==a[i][j]) recur(a, i-1, j, togglec(c), cnt+1, 'U');
        else{
            if(j-1<0 or a[i][j-1]==togglec(c)) recur(a, i-1, j, c, cnt+1, 'U');
            else recur(a, i, j-1, c, cnt+1, 'L');
        }
    }else if(dir=='U'){
        if(i-1>=0 and a[i-1][j]==a[i][j]) recur(a, i, j+1, togglec(c), cnt+1, 'R');
        else{
            if(i-1<0 or a[i-1][j]==togglec(c)) recur(a, i, j+1, c, cnt+1, 'R');
            else recur(a, i-1, j, c, cnt+1, 'U');
        }
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    vector<vector<char>> a(n, vector<char>(n));
    // a=recur(a,0,0,'*',0,'R');
    int i=0; int j=0; char c='*'; int cnt=0; char dir='R';
    while(cnt<n*n){
        a[i][j]=c;
        // cout<<cnt<<": "<<a[i][j]<<'\n';
        // cout<<a[i][j];
        if(dir=='R'){
            if(j+1<n and a[i][j+1]==a[i][j]){
                i++;
                c=togglec(c);
                cnt++;
                dir='D';
            }else{
                if(j+1>=n or a[i][j+1]==togglec(c)){
                    i++;
                    cnt++;
                    dir='D';
                }
                else{
                    j++;
                    cnt++;
                }
            }
        }else if(dir=='D'){
            if(i+1<n and a[i+1][j]==a[i][j]){
                j--;
                c=togglec(c);
                cnt++;
                dir='L';
            }
            else{
                if(i+1>=n or a[i+1][j]==togglec(c)){
                    j--;
                    cnt++;
                    dir='L';
                }
                else{
                    i++;
                    cnt++;
                }
            }
        }else if(dir=='L'){
            if(j-1>=0 and a[i][j-1]==a[i][j]){
                i--;
                c=togglec(c);
                cnt++;
                dir='U';
            }
            else{
                if(j-1<0 or a[i][j-1]==togglec(c)){
                    i--;
                    cnt++;
                    dir='U';
                }
                else{
                    j--;
                    cnt++;
                }
            }
        }else if(dir=='U'){
            if(i-1>=0 and a[i-1][j]==a[i][j]){
                j++;
                c=togglec(c);
                cnt++;
                dir='R';
            }
            else{
                if(i-1<0 or a[i-1][j]==togglec(c)){
                    j++;
                    cnt++;
                    dir='R';
                }
                else{
                    i--;
                    cnt++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}