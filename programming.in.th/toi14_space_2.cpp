#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int di[] = {0,0,1,-1};
int dj[] = {-1,1,0,0};
const size_t M = 2e3 + 10;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>m>>n;
    bitset<M> a[n],flag[n];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        char c;cin>>c;
        if(c == '0') a[i][j] = 0, flag[i][j] = 1;
        else a[i][j] = 1, flag[i][j] = 0;
    }
    queue<pii> q;
    int x = 0, y = 0, z = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(!flag[i][j]) {
            int mini = i, minj = j, maxi = i, maxj = j, cnt = 0;
            flag[i][j] = 1;
            q.push(make_pair(i,j));
            while(!q.empty()) {
                int ui = q.front().first, uj = q.front().second;q.pop();
                for(int k=0;k<4;k++) {
                    int vi = ui + di[k], vj = uj + dj[k];
                    if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) {
                        flag[vi][vj] = 1;
                        q.push(make_pair(vi,vj));
                        mini = min(mini, vi);
                        minj = min(minj, vj);
                        maxi = max(maxi, vi);
                        maxj = max(maxj, vj);
                    }
                }
                cnt++;
            }
            // cout<<"# "<<mini<<" "<<minj<<" "<<maxi<<" "<<maxj<<'\n';
            if((maxi - mini) == (maxj - minj) and cnt%(maxi - mini + 1)) y++;
            else if((maxi - mini) == (maxj - minj)) x++;
            else z++;
        }
    }
    cout<<x<<' '<<y<<' '<<z<<'\n';
    return 0;
}