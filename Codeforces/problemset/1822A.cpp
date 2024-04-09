#include <bits/stdc++.h>

using namespace std;
using pip = pair<int,pair<int,int>>;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
        int n,t;cin>>n>>t;
        vector<int> dur(n);
        vector<int> ent(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>dur[i];
            dur[i]+=cnt;
            cnt++;
        }
        for(int i=0;i<n;i++) cin>>ent[i];
        vector<pip> a;
        for(int i=0;i<n;i++){
            if(dur[i]<=t){
                a.push_back({i,{dur[i],ent[i]}});
                // cout<<"i="<<i<<" dur="<<dur[i]<<" ent="<<ent[i]<<'\n';
            }
        }
        if(a.size()<=0){
            cout<<-1<<'\n';
            continue;
        }
        int max_ent=a[0].second.second,max_idx=a[0].first;
        for(int i=1;i<a.size();i++){
            int c_ent=a[i].second.second;
            if(c_ent>max_ent){
                max_ent=c_ent;
                max_idx=a[i].first;
            }
        }
        cout<<max_idx+1<<'\n';
    }
    return 0;
}