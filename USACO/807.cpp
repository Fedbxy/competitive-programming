#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a,b,c,d;cin>>a>>b>>c>>d;
    cout<<min({abs(a - b), abs(a-c)+abs(b-d), abs(a-d)+abs(b-c)})<<'\n';
    return 0;
}