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

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        int v;cin>>v;
        cout<<closestLeft(a,v)<<"\n";
    }
    return 0;
}