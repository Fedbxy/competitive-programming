#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using pii = pair<int,int>;

// const int N = 12345 + 10;
int n;

int f(pii l, pii r) {
    return max(abs(l.first - r.first), abs(l.second - r.second));
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    vector<pii> a(n);

    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;

    vector<int> dist(n, INT_MIN);
    vector<bool> flag(n);

    int u = 0;
    int ans = 0;

    dist[u] = 0;

    int round = n-1;
    while(round--) {
        flag[u] = true;

        int next_u, mx = INT_MIN;

        for(int v=0;v<n;v++) {
            if(flag[v] == true) continue;
            dist[v] = max(dist[v], f(a[u], a[v]));
            if(dist[v] > mx) {
                mx = dist[v];
                next_u = v;
            }
        }

        u = next_u;
        ans += mx;
    }
    cout << ans << endl;
}