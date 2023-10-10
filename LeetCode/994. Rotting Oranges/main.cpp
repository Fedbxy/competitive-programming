#include <bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>> &grid) {
    vector<pair<int,int>> start;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2) start.push_back({i,j});
        }
    }
    vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),-1));
    queue<pair<int,int>> q;
    for(int i=0;i<start.size();i++){
        q.push(start[i]);
        dist[start[i].first][start[i].second]=0;
    }
    while(!q.empty()){
        int ui=q.front().first,uj=q.front().second;
        int di[4]={1,-1,0,0};
        int dj[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int vi=ui+di[i],vj=uj+dj[i];
            if(vi>=0 and vi<grid.size() and vj>=0 and vj<grid[0].size()){
                if(grid[vi][vj]==1) grid[vi][vj]=2,dist[vi][vj]=dist[ui][uj]+1,q.push({vi,vj});
            }
        }
    }
    int mx=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            mx=max(dist[i][j],mx);
        }
    }
    return mx;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    return 0;
}