/*
LANG: C++
TASK: compet
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,c;cin>>n>>c;
    int temp_n=n;
    int a[n][n];
    int teams[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
        teams[i]=1;
    }
    while(temp_n/2>=1){
        vector<int> alive;
        vector<pair<int,int>> round;
        for(int i=0;i<n;i++){
            if(teams[i]==1){
                alive.push_back(i+1);
            }
        }
        for(int i=0;i<alive.size();i+=2){
            round.push_back(make_pair(alive[i],alive[i+1]));
        }
        for(int i=0;i<round.size();i++){
            if(round[i].first!=c&&round[i].second!=c){
                if(a[round[i].first-1][round[i].second-1]==round[i].first){
                    teams[round[i].second-1]=0;
                }else{
                    teams[round[i].first-1]=0;
                }
            }else{
                if(a[round[i].first-1][round[i].second-1]==round[i].first){
                    if(round[i].second==c){
                        teams[round[i].first-1]=0;
                        c=0;
                    }else{
                        teams[round[i].second-1]=0;
                    }
                }else{
                    if(round[i].first==c){
                        teams[round[i].second-1]=0;
                        c=0;
                    }else{
                        teams[round[i].first-1]=0;
                    }
                }
            }
        }
        temp_n/=2;
    }
    for(int i=0;i<n;i++){
        if(teams[i]==1){
            cout<<i+1<<"\n";
            break;
        }
    }
    return 0;
}