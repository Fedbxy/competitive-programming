#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<bool> a(n+1);
    int idx = 0, cnt;
    for(int i=0;i<n;i++) {
        cnt = 0;
        while(cnt<m) {
            if(idx+1<=n) idx++;
            else idx = 1;
            if(!a[idx]) cnt++;
        }
        a[idx] = true;
        cout<<idx<<(i==n-1 ? '\n' : ' ');
    }
    return 0;
}