#include <bits/stdc++.h>

using namespace std;

bool bisearch(vector<int> &a,int x){
    int l=0,r=a.size()-1;
    while(l<=r){
        int mid=l+((r-l)/2);
        if(a[mid]==x){
            return true;
        }else if(a[mid]>x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return false;
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
        if(bisearch(a,v)){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}