#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--) {
        int n;cin>>n;
        vector<int> a(n+1);
        vector<bool> flag(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;i++) {
            int idx=a[i],cnt=0;
            while(true) {
                // cout<<"#"<<idx<<" "<<flag[idx]<<" "<<a[idx]<<'\n';
                if(!flag[idx]) {
                    flag[idx]=true;
                    idx=a[idx];
                    cnt++;
                } else break;
            }
            // cout<<"# "<<cnt<<'\n';
            if(cnt==1) {
                ans=max(ans,1);
            } else if(cnt==2) {
                ans=max(ans,2);
            } else {
                if(cnt%2==0) {
                    ans=max(ans,2);
                }else ans=max(ans,3);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}