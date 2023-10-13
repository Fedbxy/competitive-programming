#include <bits/stdc++.h>

using namespace std;

int cnt = 0,l,r;

void func(int n) {
    if(n<l+r) return;
    cnt++;
    func(l*n/(l+r));
    func(r*n/(l+r));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n>>l>>r;
    func(n);
    cout<<cnt+1<<'\n';
    return 0;
}