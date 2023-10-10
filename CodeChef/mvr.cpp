#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int a,b,x,y;cin>>a>>b>>x>>y;
    int ansa=a*2+b,ansb=x*2+y;
    if(ansa>ansb) cout<<"Messi\n";
    else if(ansa<ansb) cout<<"Ronaldo\n";
    else cout<<"Equal\n";
    return 0;
}