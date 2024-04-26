#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    vector<string> strs={"ab","a"};
    string prefix="";
    if(strs.size()>1){
        prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            int mn=min(strs[i].size(),prefix.size());
            for(int j=mn-1;j>=0;j--){
                if(strs[i][j]!=prefix[j]){
                    if(prefix!=""){
                        prefix.pop_back();
                    }
                }else{
                    if((strs[i].size()<prefix.size()) and ){
                        prefix=strs[i];
                    }
                }
            }
        }
    }else{
        cout<<strs[0]<<"\n";
    }
    cout<<prefix<<"\n";
    return 0;
}