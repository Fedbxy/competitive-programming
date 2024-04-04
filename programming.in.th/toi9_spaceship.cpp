#include <bits/stdc++.h>

using namespace std;

struct shop {
    int x, y, z, m, k, c;
};

int n, m, sx, sy, sz;
vector<shop> arr;
int ans = INT_MAX;

int power(int x) {
    return x * x;
}

void solve(int cnt, vector<int> sel, int cost, int cntm, int cntk, int cntc) {
    if(cnt > n or cost > ans) return;
    if(cntm >= n and cntk >= n and cntc >= n) {
        ans = min(ans, cost);
        return;
    }

    for(int i=0;i<m;i++) {
        if(find(sel.begin(), sel.end(), i) == sel.end()) {
            sel.push_back(i);

            int prev = sel[cnt-1];
            int newcost = cost;
            if(!cnt) newcost += power(arr[i].x - sx) + power(arr[i].y - sy) + power(arr[i].z - sz);
            else newcost += power(arr[i].x - arr[prev].x) + power(arr[i].y - arr[prev].y) + power(arr[i].z - arr[prev].z);
            solve(cnt + 1, sel, newcost, cntm + arr[i].m, cntk + arr[i].k, cntc + arr[i].c);

            sel.pop_back();
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> sx >> sy >> sz >> m;
    for(int i=0;i<m;i++) {
        int x, y, z, m, k, c; cin >> x >> y >> z >> m >> k >> c;
        arr.push_back({x, y, z, m, k, c});
    }

    solve(0, {}, 0, 0, 0, 0);

    cout << ans << '\n';
    return 0;
}