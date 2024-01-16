#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    char a[n][m];
    int dist[n][m];memset(dist, -1, sizeof(dist));
    bool flag[n][m];memset(flag, false, sizeof(flag));
    queue<pii> q;
    vector<pii> obj;
    
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin>>a[i][j];
        if(a[i][j] == 'W') flag[i][j] = true;
        else if(a[i][j] == 'X') q.push(make_pair(i,j)), dist[i][j] = 0, flag[i][j] = true;
        else if(a[i][j] == 'A') obj.push_back(make_pair(i,j));
    }

    while(!q.empty()) {
        int ui = q.front().first, uj = q.front().second;q.pop();
        for(int i=0;i<4;i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) flag[vi][vj] = true, dist[vi][vj] = dist[ui][uj] + 1, q.push(make_pair(vi,vj));
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) cout<<dist[i][j]<<' ';
    //     cout<<'\n';
    // }

    int cnt = 0, ans = 0;
    for(auto e:obj) {
        int ei = e.first, ej = e.second;
        // cout<<"# "<<ei<<" "<<ej<<" : "<<dist[ei][ej]<<'\n';
        if(flag[ei][ej]) {
            cnt++;
            ans += dist[ei][ej] * 2;
        }
    }
    cout<<cnt<<' '<<ans<<'\n';
    return 0;
}

/*
5 5
EEEEE
AEAEW
WEEWW
WEEXE
WWEXA

 6  5  4  5  6 
 5  4  3  4 -1 
-1  3  2 -1 -1 
-1  2  1  2  1 
-1 -1  2  1  2 
*/

/*
5 5
WEEEE
AWAEW
WEEWW
WEEXE
WWEEE
*/