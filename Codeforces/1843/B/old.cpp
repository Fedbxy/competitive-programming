#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> op(vector<ll> &a, ll l, ll r){
    for(ll i=l;i<=r;i++){
        a[i]*=-1;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a;
        for(ll i=0;i<n;i++){
            ll v;cin>>v;
            if(v!=0) a.push_back(v);
        }
        n=a.size();
        ll temp=-1,cnt=0;
        if(n==0){
            cout<<"0 0\n";
            continue;
        }
        if(n==1){
            if(a[0]<0){
                cout<<abs(a[0])<<" 1\n";
            }else{
                cout<<a[0]<<" 0\n";
            }
            continue;
        }
        for(ll i=0;i<n-1;i++){
            if(a[i]<0 and temp==-1){
                temp=i;
                // cout<<"TEMPED\n";
            }
            if(temp!=-1 and a[i]>0 and a[i+1]<=0){
                op(a,temp,i);
                cnt++;
                temp=-1;
                i=0;
                // cout<<"OPERATED\n";
            }
            if(i==n-2 and temp!=-1){
                if(a[i+1]<0){
                    op(a,temp,i+1);
                    cnt++;
                    temp=-1;
                    // cout<<"OPERATED\n";
                }else{
                    op(a,temp,i);
                    cnt++;
                    temp=-1;
                    // cout<<"OPERATED\n";
                }
            }
            if(i==n-2 and a[i+1]<0){
                op(a,i+1,i+1);
                cnt++;
            }
            // cout<<"#"<<i<<" "<<cnt<<'\n';
            // for(ll e:a) cout<<e<<' ';
            // cout<<'\n';
        }

        // for(ll e:a) cout<<e<<' ';
        // cout<<'\n';

        ll sum=0;
        for(ll i=0;i<n;i++) sum+=a[i];
        cout<<sum<<" "<<cnt<<'\n';
    }
    return 0;
}