#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<string> spot(n), plain(n);
    for(auto &e:spot) cin >> e;
    for(auto &e:plain) cin >> e;

    int ans = 0;
    vector<map<char, int>> a1(m), a2(m);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) a1[i][spot[j][i]]++, a2[i][plain[j][i]]++;
    for(int i=0;i<m;i++) {
        for(auto e:a1[i]) if(a2[i].find(e.first) != a2[i].end()) goto next;
        ans++;
        next: continue;
    }
    cout << ans << '\n';
    return 0;
}