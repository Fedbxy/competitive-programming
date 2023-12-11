#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;cin>>n;
    int ans=INT_MIN;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    for(int init=1;init<=3;init++) {
        int cnt = 0;
        int idx = init;
        for(int i=0;i<n;i++) {
            int a = arr[i][0], b = arr[i][1], g = arr[i][2];
            if(a == idx) idx = b;
            else if(b == idx) idx = a;
            if(idx == g) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<'\n';
    return 0;
}