#include <bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m));
    int di[] = {0,0,-1,1};
    int dj[] = {-1,1,0,0};

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j] == 2) q.push(make_pair(i,j)), dist[i][j] = 0;

    while(!q.empty()) {
        int ui = q.front().first, uj = q.front().second;q.pop();
        for(int i=0;i<4;i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj >= 0 and vj < m and a[vi][vj] == 1) a[vi][vj] = 2, dist[vi][vj] = dist[ui][uj] + 1, q.push(make_pair(vi,vj));
        }
    }

    int ans = INT_MIN;
    for(auto i:a) for(auto j:i) if(j == 1) return -1;
    for(auto i:dist) for(auto j:i) ans = max(ans, j);
    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int>> grid3 = {{0,2}};
    cout<<orangesRotting(grid1)<<'\n';
    return 0;
}