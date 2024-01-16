#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int di[] = {0,0,1,-1};
int dj[] = {-1,1,0,0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>m>>n;
    char a[n][m];
    bool flag[n][m];memset(flag, false, sizeof(flag));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin>>a[i][j];
        if(a[i][j] == '0') flag[i][j] = true;
    }
    queue<pii> q;
    int x = 0, y = 0, z = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(!flag[i][j]) {
            int mini = i, minj = j, maxi = i, maxj = j;
            flag[i][j] = true;
            q.push(make_pair(i,j));
            while(!q.empty()) {
                int ui = q.front().first, uj = q.front().second;q.pop();
                for(int k=0;k<4;k++) {
                    int vi = ui + di[k], vj = uj + dj[k];
                    if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) {
                        flag[vi][vj] = true;
                        q.push(make_pair(vi,vj));
                        mini = min(mini, vi);
                        minj = min(minj, vj);
                        maxi = max(maxi, vi);
                        maxj = max(maxj, vj);
                    }
                }
            }
            // cout<<"# "<<mini<<" "<<minj<<" "<<maxi<<" "<<maxj<<'\n';
            if(a[mini][minj] == '1' and (maxi - mini) == (maxj - minj)) x++;
            else if((maxi - mini) == (maxj - minj)) y++;
            else z++;
        }
    }
    cout<<x<<' '<<y<<' '<<z<<'\n';
    return 0;
}