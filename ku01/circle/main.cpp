#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int a[n+1];
    int b[n+1];
    a[0]=1;
    b[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int count=0;
    vector<pair<int,int>> c(n+1);
    vector<pair<int,int>> d(n+1);
    for(int i=0;i<n;i++){
        if(a[i]<a[i+1]){
            c[i].first=a[i];
            c[i].second=a[i+1];
        }else{
            c[i].first=a[i+1];
            c[i].second=a[i];
        }
        if(b[i]<b[i+1]){
            d[i].first=b[i];
            d[i].second=b[i+1];
        }else{
            d[i].first=b[i+1];
            d[i].second=b[i];
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<c[i].first<<" "<<c[i].second<<" | ";
    // }
    // cout<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<d[i].first<<" "<<d[i].second<<" | ";
    // }
    // cout<<"\n";
    for(int i=0;i<n;i++){
        if(c[i].first==d[i].first and c[i].second==d[i].second){
            // cout<<c[i].first<<" "<<c[i].second<<" "<<d[i].first<<" "<<d[i].second<<"\n";
            count++;
        }else if((c[i].first<d[i].first and c[i].second>d[i].first) and (c[i].second<d[i].second)){
            // cout<<c[i].first<<" "<<c[i].second<<" "<<d[i].first<<" "<<d[i].second<<"\n";
            count++;
        }else if((c[i].first>d[i].first) and (c[i].first<d[i].second and c[i].second>d[i].second)){
            // cout<<c[i].first<<" "<<c[i].second<<" "<<d[i].first<<" "<<d[i].second<<"\n";
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}