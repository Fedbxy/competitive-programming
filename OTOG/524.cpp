#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n/2;i++) cout<<i*2<<' ';
    for(int i=1;i<=n-n/2;i++) cout<<i*2-1<<' ';
    return 0;
}