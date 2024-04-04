#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    map<string, vector<int>> mp;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        int num; cin >> num;
        mp[s].resize(m);
        int x;
        for(int i=0;i<num;i++) cin >> x, mp[s][x-1]++;
    }

    while(q--) {
        string s; cin >> s;
        for(auto e:mp[s]) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}