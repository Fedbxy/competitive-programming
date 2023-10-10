#include <bits/stdc++.h>

using namespace std;
using pis=pair<pair<int,int>,string>;

// bool cmp(const pis &l, const pis &r){
//     if(l.first.first == r.first.first) return l.first.second > r.first.second;
//     return l.first.first < r.first.first;
// }

struct cmp {
    bool operator()(const pis &l, const pis &r) const {
        if(l.first.first == r.first.first) return l.first.second > r.first.second;
        return l.first.first < r.first.first;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int count=0;
    priority_queue<pis, vector<pis>, cmp> pq;
    while(true){
        string cmd;cin>>cmd;
        if(cmd=="Exit") break;
        if(cmd=="New"){
            string name;cin>>name;
            int p;cin>>p;
            pq.push({{p,count},name});
            count++;
        }else{
            cout<<pq.top().second<<'\n';
            pq.pop();
        }
    }
    return 0;
}