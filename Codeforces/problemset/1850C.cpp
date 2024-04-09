#include <bits/stdc++.h>

using namespace std;

const int N=8;
char a[N][N];

void solve() {
    string ans;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>a[i][j];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        if(a[i][j]!='.') {
            int y=0;
            while(true) {
                if(a[i+y][j]=='.') goto end;
                ans.push_back(a[i+y][j]);
                if(i+y+1<8) {
                    y++;
                    continue;
                } else goto end;
            }
        }
    }
    end:
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
    return 0;
}