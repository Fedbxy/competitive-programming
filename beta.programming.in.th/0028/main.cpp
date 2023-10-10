#include <bits/stdc++.h>

using namespace std;

struct team {
    string name;
    int total_score=0,scored=0,lost=0;
};

bool cmp(const team &l,const team &r){
    if(l.total_score==r.total_score){
        if((l.scored-l.lost)==(r.scored-r.lost)){
            return l.scored>r.scored;
        }
        return (l.scored-l.lost)>(r.scored-r.lost);
    }
    return l.total_score>r.total_score;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    team a[4];
    int scoreboard[4][4];
    for(int i=0;i<4;i++){
        cin>>a[i].name;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>scoreboard[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=j){
                if(scoreboard[i][j]>scoreboard[j][i]){
                    a[i].total_score+=3;
                }else if(scoreboard[i][j]==scoreboard[j][i]){
                    a[i].total_score+=1;
                }
                a[i].scored+=scoreboard[i][j];
                a[i].lost+=scoreboard[j][i];
            }
        }
    }
    // for(int i=0;i<4;i++){
    //     cout<<a[i].name<<" "<<a[i].total_score<<" "<<a[i].scored<<" "<<a[i].lost<<"\n";
    // }
    sort(a,a+4,cmp);
    for(int i=0;i<4;i++){
        cout<<a[i].name<<" "<<a[i].total_score<<"\n";
    }
    return 0;
}