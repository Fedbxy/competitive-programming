#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int n,m;
const int N = 2e3 + 10;
char a[N][N];
bool flag[N][N];

int di[] = {-1,1,0,0,-1,-1,1,1};
int dj[] = {0,0,-1,1,-1,1,-1,1};

void bfs(int si, int sj) {
    flag[si][sj] = true;
    queue<pii> q;q.push(make_pair(si,sj));
    while(!q.empty()) {
        int ui = q.front().first, uj = q.front().second;q.pop();
        for(int i=0;i<8;i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if(vi >= 0 and vi < n and vj >= 0 and vj < m and !flag[vi][vj]) flag[vi][vj] = true, q.push(make_pair(vi,vj));
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin>>a[i][j];
        if(a[i][j] == '0') flag[i][j] = true;
    }
    int ans = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(!flag[i][j]) {
            ans++;
            bfs(i,j);
        }
    }
    cout<<ans<<'\n';
    return 0;
}