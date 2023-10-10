#include <bits/stdc++.h>

using namespace std;

int closestLeft(vector<int> &a,int x){
    int l=0,r=a.size()-1;
    int ans=0;
    while(l<=r){
        int mid=l+((r-l)/2);
        if(a[mid]<=x){
            ans=mid+1;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

int closestRight(vector<int> &a,int x){
    int l=0,r=a.size()-1;
    int ans=0;
    while(l<=r){
        int mid=l+((r-l)/2);
        if(a[mid]>=x){
            ans=mid+1;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int k;cin>>k;
    for(int i=1;i<=k;i++){
        int l,r;cin>>l>>r;
        int lr=closestLeft(a,r),rl=closestRight(a,l);
        if(lr==0||rl==0){
            cout<<0<<"\n";
        }else{
            cout<<lr-rl+1<<" ";
        }
    }
    cout<<"\n";
    return 0;
}