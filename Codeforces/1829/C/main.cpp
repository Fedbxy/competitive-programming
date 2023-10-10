#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a,b,ab;
        for(int i=0;i<n;i++){
            int m;cin>>m;
            string s;cin>>s;
            if(s=="00") continue;
            if(s=="10") a.push_back(m);
            if(s=="01") b.push_back(m);
            if(s=="11") ab.push_back(m);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(ab.begin(),ab.end());
        int mn=INT_MAX;
        if(a.size()==0 and ab.size()==0){
            cout<<-1<<'\n';
            continue;
        }
        if(b.size()==0 and ab.size()==0){
            cout<<-1<<'\n';
            continue;
        }
        if(a.size()>0 and b.size()>0){
            mn=min(mn,a[0]+b[0]);
        }
        if(ab.size()>0){
            mn=min(mn,ab[0]);
        }
        cout<<mn<<'\n';
    }
    return 0;
}