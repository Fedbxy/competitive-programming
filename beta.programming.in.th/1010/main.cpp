#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m,n;cin>>m>>n;
    char a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char v;cin>>v;
            if(v<'z'&&v>'a'){
                a[i][j]=v-32;
            }else{
                a[i][j]=v;
            }
        }
    }
    int q;cin>>q;
    while(q--){
        string s;cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]<'z'&&s[i]>'a'){
                s[i]=s[i]-32;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==s[0]){
                    if(s.size()>1){
                        if(a[i-1][j-1]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i-k][j-k]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i-1][j]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i-k][j]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i][j-1]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i][j-k]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i+1][j-1]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i+k][j-k]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i-1][j+1]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i-k][j+k]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i+1][j]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i+k][j]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i][j+1]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i][j+k]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                        if(a[i+1][j+1]==s[1]){
                            bool b=false;
                            for(int k=2;k<s.size();k++){
                                if(a[i+k][j+k]!=s[k]){
                                    b=true;
                                    break;
                                }
                            }
                            if(!b){
                                cout<<i<<" "<<j<<"\n";
                                goto f;
                            }
                        }
                    }else{
                        cout<<i<<" "<<j<<"\n";
                        goto f;
                    }
                }
            }
        }
        f:
        continue;
    }
    return 0;
}