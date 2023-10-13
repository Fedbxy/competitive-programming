#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    n=n*2-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(j==0 or j==n-1) cout<<"#";
            else if(i==j) cout<<"#";
            else cout<<" ";
        }
        cout<<'\n';
    }
    return 0;
}