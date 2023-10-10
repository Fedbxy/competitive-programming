/*
LANG: C++
TASK: woods
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,w,l;cin>>n>>w>>l;
    vector<vector<int>> a(n,vector<int>(w));
    for(int i=0;i<n;i++){
        int n_i;cin>>n_i;
        for(int j=0;j<n_i;j++){
            int v;cin>>v;
            a[i][v-1]=1;
        }
    }
    int ans=0;
    if(l>0){
        for(int i=0;i<w;i++){
            if(a[0][i]==1){
                for(int t=i-l;t<i-l+(l*2+1);t++){
                    if(t>=0&&t<w){
                        int count=0;
                        for(int j=0;j<n;j++){
                            bool r_found=0;
                            for(int k=t-l;k<t-l+(l*2+1);k++){
                                if(k>=0&&k<w){
                                    if(a[j][k]==1){
                                        r_found=1;
                                        count++;
                                        break;
                                    }
                                }
                            }
                            if(!r_found){
                                break;
                            }
                        }
                        if(count==n){
                            ans=1;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}