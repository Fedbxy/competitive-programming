#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> s;
vector<int> b;
int mn=INT_MAX;

void f(int idx,int sum_s,int sum_b,int cnt){
    if(idx==n){
        if(cnt>=1){
            int ans=abs(sum_s-sum_b);
            // cout<<ans<<"\n";
            mn=min(mn,ans);
        }
        return;
    }
    f(idx+1,sum_s,sum_b,cnt);
    f(idx+1,sum_s*=s[idx],sum_b+=b[idx],cnt+1);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;s.push_back(temp);
        cin>>temp;b.push_back(temp);
    }
    f(0,1,0,0);
    cout<<mn<<"\n";
    return 0;
}