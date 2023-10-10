#include <bits/stdc++.h>

using namespace std;

int lucky_num(string s){
    int num_mx=INT_MIN,num_mn=INT_MAX;
    for(int i=0;i<s.size();i++){
        num_mx=max(num_mx,int(s[i])-48);
        num_mn=min(num_mn,int(s[i])-48);
    }
    return num_mx-num_mn;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int l,r;cin>>l>>r;
        int unluckiest=INT_MAX;
        int theluckynum;
        if(r-l>=100){
            theluckynum=l;
            while(theluckynum%100!=0) theluckynum+=1;
        }else{
            for(int i=l;i<=r;i++){
                string num=to_string(i);
                int lucky=lucky_num(num);
                if(unluckiest>lucky){
                    unluckiest=lucky;
                    theluckynum=i;
                }
            }
        }
        cout<<theluckynum<<'\n';
    }
    return 0;
}