#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;

    int ans = 0;
    multiset<int> sel;
    vector<int> dist(n, INT_MAX);
    // vector<bool> flag(n);
    int u = 0; dist[u] = 0;
    for(int u=0;u<n-1;u++) {
        // flag[u] = true;
        int next_u, mn = INT_MAX;
        for(int v=u+1;v<n;v++) {
            // if(flag[v]) continue;
            dist[v] = min(dist[v], abs(a[u].first - a[v].first) + abs(a[u].second - a[v].second));
            if(dist[v] < mn) {
                mn = dist[v];
                next_u = v;
            }
        }
        swap(a[u+1], a[next_u]);
        swap(dist[u+1], dist[next_u]);
        ans += mn;
        sel.insert(mn);
    }

    auto itr = sel.rbegin();
    for(int i=0;i<k-1;i++) {
        ans -= *itr;
        itr++;
    }
    cout << ans << '\n';
    return 0;
}