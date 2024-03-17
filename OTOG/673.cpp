#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("input.txt","r",stdin);
    int score;
    while(cin>>score){
        if(score>=50){
            cout<<"P\n";
        }else{
            cout<<"-\n";
        }
    }
    return 0;
}