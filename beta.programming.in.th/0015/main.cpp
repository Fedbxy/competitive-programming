#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int a,b,c;cin>>a>>b>>c;
    cout<<max(b-a-1,c-b-1)<<"\n";
    return 0;
}